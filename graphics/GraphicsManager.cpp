#include "GraphicsManager.h"
#include "../geometry/model.h"

GraphicsManager::GraphicsManager(glm::vec3* sun) : sun(sun){
    currentPath = std::filesystem::current_path();
    camera = new Camera();
    initShaders();
    setupPipeline();
}

GraphicsManager::~GraphicsManager(){
    for(auto shader : shaders){
        delete(shader.second);
    }
    delete(lightShader);
    delete(envShader);
    delete(camera);
}

void GraphicsManager::initShaders(){
    lightShader = new Shader("resources/shader/deferredVert.glsl", "resources/shader/deferredFrag.glsl", {"gPosition", "gNormal", "gAlbedo", "glSpec"});
    envShader = new Shader("resources/shader/envVert.glsl", "resources/shader/envFrag.glsl", {});
    shaders.insert({drawable_t::hash_value_t::HASH_VALUE_NONE, new Shader("resources/shader/defaultVert.glsl", "resources/shader/defaultFrag.glsl", {})});
    shaders.insert({drawable_t::hash_value_t::HASH_VALUE_STANDARD, new Shader("resources/shader/standardVert.glsl", "resources/shader/standardFrag.glsl", {"tintpalettetex","_0xe9f32960","diffusetex","detailtexarrayn","bumptex","speculartex","speculartex2"})});
    shaders.insert({drawable_t::hash_value_t::HASH_VALUE_STANDARD_DIRT, new Shader("resources/shader/standardDirtVert.glsl", "resources/shader/standardDirtFrag.glsl", {"tintpalettetex", "_0xe9f32960", "diffusetex", "detailtexarrayn", "diffusetex2", "bumptex", "speculartex", "speculartex2", "_0x56d855c5"})});
    shaders.insert({drawable_t::hash_value_t::HASH_VALUE_STANDARD_2LYR, new Shader("resources/shader/standard2lyrVert.glsl", "resources/shader/standard2lyrFrag.glsl", {"tintpalettetex", "lyr0diffusetex", "lyr0normaltex", "lyr0materialatex", "lyr0materialbtex", "lyr1diffusetex", "lyr1normaltex", "lyr1materialatex", "lyr1materialbtex", "dirtdiffusetex", "controltexturetex", "aotexturetex", "detailtexarrayn"})});

    getTexture(std::string("blank_black"));
}

void GraphicsManager::setupPipeline(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0,0,W_WIDTH, W_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // configure g-buffer framebuffer
    // ------------------------------
    glGenFramebuffers(1, &gBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
    // position color buffer
    glGenTextures(1, &gPosition);
    glBindTexture(GL_TEXTURE_2D, gPosition);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, W_WIDTH, W_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gPosition, 0);

    // normal color buffer
    glGenTextures(1, &gNormal);
    glBindTexture(GL_TEXTURE_2D, gNormal);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, W_WIDTH, W_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, gNormal, 0);
    // color + specular color buffer
    glGenTextures(1, &gAlbedo);
    glBindTexture(GL_TEXTURE_2D, gAlbedo);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, W_WIDTH, W_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, gAlbedo, 0);

    glGenTextures(1, &glSpec);
    glBindTexture(GL_TEXTURE_2D, glSpec);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, W_WIDTH, W_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT3, GL_TEXTURE_2D, glSpec, 0);

    // tell OpenGL which color attachments we'll use (of this framebuffer) for rendering 
    unsigned int attachments[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
    glDrawBuffers(4, attachments);
    // create and attach depth buffer (renderbuffer)
    unsigned int rboDepth;
    glGenRenderbuffers(1, &rboDepth);
    glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, W_WIDTH, W_HEIGHT);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);
    // finally check if framebuffer is complete
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "Framebuffer not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    //create Uniform Buffer Object for the transfrom matrices
    glGenBuffers(1, &uboMatrices);
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 3 * sizeof(glm::mat4) + sizeof(glm::vec2), NULL, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    glBindBufferBase(GL_UNIFORM_BUFFER, 0, uboMatrices);
}

void GraphicsManager::preRender(){
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    updateUBOMatrices();

    glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_BLEND);
}

void GraphicsManager::postRender(){
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDepthMask(GL_FALSE);
    envShader->use();
    envShader->setVec3("rot", camera->Front);
    envShader->setVec3("sun", *sun);
    renderQuad();
    glUseProgram(0);
    glDepthMask(GL_TRUE);

    lightShader->use();
    lightShader->setVec3("viewDir", camera->Front);
    lightShader->setVec3("sun", *sun);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gPosition);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, gNormal);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, gAlbedo);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, glSpec);

    renderQuad();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

//would be better event based
void GraphicsManager::updateUBOMatrices(){
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 1 * sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(*camera->view));
    glBufferSubData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(*camera->projection));
    glBufferSubData(GL_UNIFORM_BUFFER, 3 * sizeof(glm::mat4), sizeof(glm::vec2), glm::value_ptr(screenSize));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void GraphicsManager::updateModelMatrix(Model* model){
    auto trans = model->getTransfrom();
    glBindBuffer(GL_UNIFORM_BUFFER, uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(trans));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

Shader* GraphicsManager::getShader(drawable_t::hash_value_t name){
    auto shaderIt = shaders.find(name);
    if(shaderIt == shaders.end()){
        return shaders.at(drawable_t::hash_value_t::HASH_VALUE_NONE);
    } else {
        return shaderIt->second;
    }
}


GLuint GraphicsManager::getTexture(std::string name){
    auto texIt = textures.find(name);
    if(texIt == textures.end()){
        std::string path = currentPath;
        path.append("/resources/textures/");
        path.append(name);
        path.append(".dds");
        auto tex = utility::CreateTexture(path.c_str());
        if(!tex){
            if(!name.empty()){
                std::cout << "unable to load Texture: " << name  << std::endl;
            }
            return textures.at("blank_black");
        }
        textures.insert({name, tex});
        return tex;
    } else {
        return texIt->second;
    }
}

// renderQuad() renders a 1x1 XY quad in NDC
// -----------------------------------------
void GraphicsManager::renderQuad()
{
    if (quadVAO == 0)
    {
        float quadVertices[] = {
            // positions        // texture Coords
            -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
             1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
             1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        };
        // setup plane VAO
        glGenVertexArrays(1, &quadVAO);
        glGenBuffers(1, &quadVBO);
        glBindVertexArray(quadVAO);
        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    }
    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}