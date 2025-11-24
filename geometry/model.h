#pragma once

#include "drawable.h"
#include "../graphics/Shader.h"
#include "../util/libs.hpp"
#include "../util/utility.hpp"
#include "../graphics/GraphicsManager.h"

#include <iostream>
#include <variant>

class Model{
    public:
        class Mesh;

        Model(drawable_t* drawable_model, GraphicsManager* world);
        ~Model();
        void draw();

        std::string getName(){return name;}
        glm::vec3 getPos() {return position;}
        void setPos(glm::vec3 pos) {position = pos; transform();}
        glm::quat getRot() {return rotation;}
        glm::vec3 getRotEuler() {return glm::eulerAngles(rotation);}
        void setRotEuler(glm::vec3 rot){rotation = glm::quat(rot); transform();}
        glm::mat4 getTransfrom(){return transformMatrix;}
        std::vector<std::string>* getShader(){return &shaderName;}
    
    private:
        std::string name;
        glm::vec3 position = {0,0,0};
        glm::quat rotation = glm::quat(glm::vec3(0,0,0));
        glm::mat4 transformMatrix;
        drawable_t* drawable;
        std::vector<Mesh*> meshes;
        std::vector<Shader*> shaders;
        std::vector<std::string> shaderName;

        void transform();

public:
    class Mesh{
        public:
            Mesh(uint16_t id, drawable_t* drawable, Shader* shader, std::vector<GLuint> textures);
            Mesh();
            ~Mesh();
            void draw();

        private:
            GLuint VAO, EBO, VBO[52];
            uint32_t indicesSize;
            Shader* shader;
            std::vector<GLuint> textures;
            using varType = std::variant<std::vector<float>*, std::vector<uint8_t>*>;
            void setup(const std::vector<std::pair<drawable_t::vertex_layout_type_t, varType>> &allVertices, const std::vector<uint16_t> &indices);
    };
};