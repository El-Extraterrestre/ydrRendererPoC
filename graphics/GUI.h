#pragma once

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_sdl3.h"
#include "ImGUI/imgui_impl_opengl3.h"
#include "../util/libs.hpp"
#include "../geometry/World.h"

class GUI{
    public:
        GUI(SDL_Window* window, SDL_GLContext context, World* world);
        ~GUI();

        void processEvents(SDL_Event &event);
        void update();

    private:
        World* world;
        const char* modelNames[1] = {"gothic_coffee_table"};
        int current_modelName = 0;
        int selected_model = 0;


};