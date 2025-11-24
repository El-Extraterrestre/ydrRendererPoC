#include "model.h"

Model::Model(drawable_t* drawable_model, GraphicsManager* graphicsMgr) : drawable(drawable_model){
    name = drawable->name();
    std::cout << name << " loading" << std::endl;

    auto shaderList = drawable->shader_group()->shader_list()[0];
    std::vector<std::vector<GLuint>> textureList;
    for(auto s : shaderList){
        auto shaderHash = s->shader()->shader_type()->hash_value();
        shaderName.push_back(utility::hashToString.at(shaderHash));
        shaders.push_back(graphicsMgr->getShader(shaderHash));
        std::vector<GLuint> textures;
        for(auto tex : s->shader()->texture_info()->texture_data()[0]){
            std::string name;
            if(tex->textures()->texture()){
                name = tex->textures()->texture()->name();
            } else {
                name = "";
            }
            textures.push_back(graphicsMgr->getTexture(name));
        }
        textureList.push_back(textures);
    }

    auto model = drawable->lod_h()->model_list()[0][0]->model();
    for(int i = 0; i < model->geometry_list()[0].size(); i++) {
        auto id = model->shader_id()[0][i];
        meshes.push_back(new Mesh(i, drawable, shaders[id], textureList[id]));
    }

    transform();
    std::cout << name << " loaded!" << std::endl;
}

Model::~Model(){
    delete(drawable);
    for(auto mesh : meshes){
        delete(mesh);
    }
}

void Model::transform(){
    glm::mat4 trans = glm::mat4(1);
    auto rot = glm::mat4_cast(rotation);
    trans = glm::translate(trans, position);
    transformMatrix = trans * rot;
}

void Model::draw(){
    for(auto mesh : meshes){
        mesh->draw();
    }
}

Model::Mesh::Mesh(uint16_t id, drawable_t* drawable, Shader* shader, std::vector<GLuint> textures) : shader(shader), textures(textures){
    auto model = drawable->lod_h()->model_list()[0][0]->model();
    auto shaderDataId = model->shader_id()[0][id];

    auto geometry = model->geometry_list()[0][id]->geometry();
    auto vertexData = geometry->vertex_data()->verticies()[0];
    std::vector<std::pair<drawable_t::vertex_layout_type_t, varType>> allVerticies;
    for(auto vData : vertexData){
        auto vType = vData->type();
        if(vType != drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_NONE){
            auto normals = new std::vector<float>();
            std::vector<drawable_t::normals_t*>* normalList;
            std::pair<drawable_t::vertex_layout_type_t, varType> vertexList;
            switch (vType)
            {
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_POSITION :
                vertexList = make_pair(vType, &static_cast<drawable_t::float_list_t*>(vData->data())->data()[0]);
                break;
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_NORMAL :
                normalList = &static_cast<drawable_t::normal_list_t*>(vData->data())->data()[0];
                for(auto normal : *normalList){
                    normals->push_back(normal->x());
                    normals->push_back(normal->y());
                    normals->push_back(normal->z());
                    normals->push_back(normal->w());
                }
                vertexList = make_pair(vType, normals);
                break;
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_COLOR :
                vertexList = make_pair(vType, &static_cast<drawable_t::byte_list_t*>(vData->data())->data()[0]);
                break;
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_TEXTURE :
                vertexList = make_pair(vType, &static_cast<drawable_t::float_list_t*>(vData->data())->data()[0]);
                break;
            }
            allVerticies.push_back(vertexList);
        }
    }

    auto indices = &geometry->indicies_data()->indicies()[0];
    indicesSize = indices->size();

    setup(allVerticies, *indices);
}

Model::Mesh::~Mesh(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, VBO);
    glDeleteBuffers(1, &EBO);
}

void Model::Mesh::setup(const std::vector<std::pair<drawable_t::vertex_layout_type_t, varType>> &allVertices, const std::vector<uint16_t> &indices){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(allVertices.size(), VBO);
    glGenBuffers(1, &EBO);
  
    glBindVertexArray(VAO);

    GLuint i = 0;
    for(auto vDataRaw : allVertices){
        std::visit([&i, this, &vDataRaw](const auto& vData) {
            glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
            glBufferData(GL_ARRAY_BUFFER, vData->size() * (vDataRaw.first == drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_COLOR ? sizeof(uint8_t) : sizeof(float)), vData->data(), GL_STATIC_DRAW);
            
            GLint size = 0;
            GLenum type = GL_FLOAT;
            switch (vDataRaw.first)
            {
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_POSITION:
                size = 3;
                break;
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_NORMAL:
                size = 4;
                break;
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_COLOR:
                size = 4;
                type = GL_UNSIGNED_BYTE;
                break;
            case drawable_t::vertex_layout_type_t::VERTEX_LAYOUT_TYPE_TEXTURE:
                size = 2;
                break;
            }

            glVertexAttribPointer(i, size, type, GL_FALSE, 0, (void*)0);
            glEnableVertexAttribArray(i);
        }, vDataRaw.second);
        i++;
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint16_t), indices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Model::Mesh::draw(){
    shader->use();
    if(shader->isDefault()){
        glPolygonMode(GL_FRONT, GL_LINE);
    } else {
        int i = 0;
        for(auto tex : textures){
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, tex);
            i++;
        }
    }

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indicesSize, GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);

    if(shader->isDefault()){
        glPolygonMode(GL_FRONT, GL_FILL);
    }
}