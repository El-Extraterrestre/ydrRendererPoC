#pragma once

#ifdef _WIN32
	#include <Windows.h>
#endif

#define GLM_ENABLE_EXPERIMENTAL

#include <SDL3/SDL.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3_image/SDL_image.h>
#include <GL/glew.h>
#include <GL/gl.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"

#include "external/glm/glm/glm.hpp"
#include "external/glm/glm/gtc/matrix_transform.hpp"
#include "external/glm/glm/gtc/type_ptr.hpp"
#include "external/glm/glm/gtc/quaternion.hpp"

#pragma GCC diagnostic pop