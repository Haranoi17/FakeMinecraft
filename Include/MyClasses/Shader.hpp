#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include <fstream>

class Shader
{
public:

    Shader(const char*, const char*);
    ~Shader();

    void use() const;
    void setMat4(const GLuint&, const glm::mat4&) const;
    
    GLuint getID() const;

private:

    void checkCompilationVertexShader() const;
    void checkCompilationFragmentShader() const;
    void checkLinkingProgram() const;

    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
};