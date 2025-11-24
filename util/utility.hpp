#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "libs.hpp"

#include "../geometry/drawable.h"
#include "kaitai/kaitaistream.h"

#include "gli/gli.hpp"

/*
* Hilfsfunktionen zum Kompilieren und Linken von Shadern.
* Siehe https://elminster.hs-mittweida.de/doku.php?id=gpu:shader_drawcall#shader-spezifikation
*/

namespace utility {

	bool CompileShader(GLuint shader, const char* filename);

	bool LinkShaderProgram(GLuint program);

	void PrintOpenGLInformation();

    drawable_t* loadYDR(std::string filename);

	//https://github.com/g-truc/gli/tree/master
	GLuint CreateTexture(char const* Filename);

	extern std::map<drawable_t::hash_value_t, std::string> hashToString;

} // end of namespace
#endif //UTILITY_H