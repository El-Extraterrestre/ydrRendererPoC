#ifndef SHADER_H
#define SHADER_H
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "../util/libs.hpp"
  

class Shader
{
public:
    // the program ID
    unsigned int ID;
  
    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath, std::vector<std::string> texNames);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setMatrix(const std::string &name, glm::mat4 &value) const;
    void setVec3(const std::string &name, glm::vec3 &value) const;
    bool isDefault(){return defaultSh;}

    //std::vector<GLint> texLocation;
private:
    void loadTextureLocation(std::vector<std::string> texNames);
    bool defaultSh = false;
};
  
#endif