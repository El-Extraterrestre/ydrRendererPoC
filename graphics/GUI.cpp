
#include "GUI.h"

GUI::GUI(SDL_Window* window, SDL_GLContext context, World* world) : world(world){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImGui_ImplSDL3_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init();
    ImGui::StyleColorsDark();
}

GUI::~GUI(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

void GUI::processEvents(SDL_Event &event){
    ImGui_ImplSDL3_ProcessEvent(&event);
}

void GUI::update(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("GUI");

    if(ImGui::Combo("Add Model", &current_modelName, modelNames, IM_ARRAYSIZE(modelNames))){
        std::string path = "resources/models/";
        path.append(modelNames[current_modelName]);
        path.append(".ydr");
        world->addYDR(path);
    }

    ImGui::BeginChild("Scrolling", ImVec2(150, 0), true);
        int i = 0;
        for (auto model : world->models){
            if(ImGui::Selectable(model->getName().c_str(), selected_model == i)){
                selected_model = i;
            }
            i++;
        }
    ImGui::EndChild();

    ImGui::SameLine();
    ImGui::BeginGroup();
        ImGui::Text("Details:");
        ImGui::Separator();
        if (selected_model >= 0 && selected_model < world->models.size())
        {
            auto model = world->models[selected_model];
            ImGui::Text("Name: %s", model->getName().c_str());
            if(ImGui::Button("Delete")){
                world->removeYDR(selected_model);
            }
            ImGui::Spacing();
            ImGui::Text("Position:");
            auto pos = model->getPos();
            float p[3] = {pos.x, pos.y, pos.z};
            ImGui::DragFloat3("##Position", p, 0.1f);
            model->setPos(glm::vec3(p[0], p[1], p[2]));
            ImGui::Text("Rotation:");
            auto rot = model->getRotEuler();
            float r[3] = {rot.x, rot.y, rot.z};
            ImGui::DragFloat3("##Rotation", r, 0.1f);
            model->setRotEuler(glm::vec3(r[0], r[1], r[2]));

            ImGui::Spacing();
            ImGui::BeginChild("Meshes");
            for(auto shaderName : *model->getShader()){
                ImGui::Text(shaderName.c_str());
            }
            ImGui::EndChild();
        }
        else
        {
            ImGui::Text("No item selected.");
        }
    ImGui::EndGroup();


    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}