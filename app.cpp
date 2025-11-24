#include <iostream>
#include <SDL3/SDL_main.h>
#include "util/libs.hpp"
#include "globals.h"

#include "geometry/World.h"
#include "graphics/Camera.h"
#include "graphics/GUI.h"
#include "util/utility.hpp"

void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}
void processInput(SDL_Event &event, World* world);

int main(int argc, char *argv[]){

    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Could not initialize SDL with error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("RDR ydr RenderEngine", W_WIDTH, W_HEIGHT, SDL_WINDOW_RESIZABLE);
    if(window == nullptr){
        SDL_Log("Could not create window with error: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    if(surface == nullptr){
        SDL_Log("Could not create surface with error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if(glContext == nullptr){
        SDL_Log("Could not create openGL Context with error: %s\n", SDL_GetError());
        SDL_DestroySurface(surface);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    GLenum glewStatus = glewInit();

    glEnable              ( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );

    bool focusWindow = true;
    SDL_SetWindowRelativeMouseMode(window, focusWindow);

    utility::PrintOpenGLInformation();
    std::cout << "init done" << std::endl;

    if (!GLEW_EXT_texture_compression_s3tc){
        std::cerr << "S3TC is not supported but necessary!\nClosing application!" << std::endl;
		SDL_GL_DestroyContext(glContext);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
    }

    World* world = new World();
    std::cout << "world init done" << std::endl;
    world->graphicsManager->resize(W_WIDTH, W_HEIGHT);
    world->addYDR();
    std::cout << "world done" << std::endl;

    GUI gui(window, glContext, world);
    std::cout << "gui done" << std::endl;

    SDL_Event event;
    SDL_zero(event);
    bool running = true;
    while(running){
        while(SDL_PollEvent(&event)){
            switch(event.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (event.key.key)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_TAB:
                    focusWindow = !focusWindow;
                    SDL_SetWindowRelativeMouseMode(window, focusWindow);
                    break;
                }
                break;
	        case SDL_EVENT_WINDOW_RESIZED:
	        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
                int width, height;
	        	SDL_GetWindowSizeInPixels(window, &width, &height);
	        	world->graphicsManager->resize(width, height);
	        	break;
            }
            if(focusWindow){
                processInput(event, world);
            } else {
                gui.processEvents(event);
            }
        }

        world->render();
        gui.update();
        SDL_GL_SwapWindow(window);
    }

    delete(world);
    SDL_GL_DestroyContext(glContext);
    SDL_DestroySurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void processInput(SDL_Event &event, World* world){
    switch(event.type)
    {
    case SDL_EVENT_MOUSE_MOTION:
        world->graphicsManager->camera->ProcessMouseMovement(event.motion.xrel, event.motion.yrel);
        break;
    case SDL_EVENT_KEY_DOWN:
        switch (event.key.key)
        {
        case SDLK_W:
        case SDLK_UP:
            world->graphicsManager->camera->ProcessKeyboard(FORWARD, 0.1f);
            break;
        case SDLK_S:
        case SDLK_DOWN:
            world->graphicsManager->camera->ProcessKeyboard(BACKWARD, 0.1f);
            break;
        case SDLK_A:
        case SDLK_LEFT:
            world->graphicsManager->camera->ProcessKeyboard(LEFT, 0.1f);
            break;
        case SDLK_D:
        case SDLK_RIGHT:
            world->graphicsManager->camera->ProcessKeyboard(RIGHT, 0.1f);
            break;
        case SDLK_Q:
            world->graphicsManager->camera->ProcessKeyboard(UP, 0.1f);
            break;
        case SDLK_E:
            world->graphicsManager->camera->ProcessKeyboard(DOWN, 0.1f);
            break;
        }
        break;
	}
}