#include "World.h"

World::World(){
    *sun = glm::vec3(-0.2, -0.1, -0.8);
    graphicsManager = new GraphicsManager(sun);
}

World::~World(){
    for(auto model : models){
        delete(model);
    }
    delete(sun);
    delete(graphicsManager);
}

void World::render(){
    graphicsManager->preRender();
    for(auto model : models){
        graphicsManager->updateModelMatrix(model);
        model->draw();
    }
    graphicsManager->postRender();
}

void World::addYDR(std::string filename){
    models.push_back(new Model(utility::loadYDR(filename), graphicsManager));
}

void World::addYDR(){
    addYDR(std::string("resources/models/gothic_coffee_table.ydr"));
}

void World::removeYDR(int i){
    delete(models[i]);
    models.erase(models.begin() + i);
}