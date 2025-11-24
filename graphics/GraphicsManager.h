#pragma once

#include "../util/libs.hpp"
#include "Shader.h"
#include "Camera.h"
#include "../geometry/drawable.h"
#include "../util/utility.hpp"
#include "../globals.h"

#include <string>
#include <vector>
#include <map>
#include <filesystem>

class Model;

class GraphicsManager{
    public:
        GraphicsManager(glm::vec3* sun);
        ~GraphicsManager();

        Camera* camera;

        Shader* getShader(drawable_t::hash_value_t name);
        GLuint getTexture(std::string name);
        void addTexture(std::string name);

        void resize(int width, int height) {screenSize = glm::vec2(width, height);}

        void setupPipeline();
        void preRender();
        void postRender();
        void updateModelMatrix(Model* model);

        void renderQuad();

    private:
        unsigned int gBuffer;
        unsigned int gPosition, gNormal, gAlbedo, glSpec;
        unsigned int uboMatrices;
        unsigned int quadVAO = 0;
        unsigned int quadVBO;
        void initShaders();
        void updateUBOMatrices();

        std::string currentPath;
        Shader* lightShader;
        Shader* envShader;
        glm::vec2 screenSize;
        glm::vec3* sun;
        std::map<drawable_t::hash_value_t, Shader*> shaders;
        std::map<std::string, GLuint> textures;
};