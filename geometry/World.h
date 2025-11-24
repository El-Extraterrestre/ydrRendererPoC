#pragma once

#include "model.h"
#include "../graphics/Camera.h"
#include "../graphics/GraphicsManager.h"
#include "../util/utility.hpp"

#include <string>
#include <typeinfo>

class World{

    public:
        World();
        ~World();

        void render();
        void addYDR();
        void addYDR(std::string filename);
        void removeYDR(int i);
        void setLight();

        GraphicsManager* graphicsManager;

        std::vector<Model*> models;
        glm::vec3* sun = new glm::vec3();
};