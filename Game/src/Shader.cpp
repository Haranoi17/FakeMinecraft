#include <Shader.hpp>
#include <iostream>
#include <GL/glew.h>

Shader::Shader(const std::filesystem::path& vertexShaderPath, const std::filesystem::path& fragmentShaderPath)
{
    programID = glCreateProgram();
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexShaderSRC;
    std::ifstream vertexShaderFile;
    std::stringstream vertexShaderStream;

    vertexShaderFile.open(vertexShaderPath.c_str());
    vertexShaderStream << vertexShaderFile.rdbuf();
    vertexShaderFile.close();

    vertexShaderSRC = vertexShaderStream.str();
    const char* vertexSrc = vertexShaderSRC.c_str();

    std::string fragmentShaderSRC;
    std::ifstream fragmentShaderFile;
    std::stringstream fragmentShaderStream;

    fragmentShaderFile.open(fragmentShaderPath.c_str());
    fragmentShaderStream << fragmentShaderFile.rdbuf();
    fragmentShaderFile.close();

    fragmentShaderSRC = fragmentShaderStream.str();

    const char* fragmetnSrc = fragmentShaderSRC.c_str(); 

    glShaderSource(vertexShaderID, 1, &vertexSrc, NULL);
    glShaderSource(fragmentShaderID, 1, &fragmetnSrc, NULL);

    glCompileShader(vertexShaderID);
    checkCompilationVertexShader();

    glCompileShader(fragmentShaderID);
    checkCompilationFragmentShader();

    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    
    glLinkProgram(programID);
    checkLinkingProgram();

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void Shader::checkCompilationVertexShader() const
{
    int succes;
    char infoLog[512];

    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &succes);
    if(!succes)
    {
        glGetShaderInfoLog(vertexShaderID, sizeof(infoLog), NULL, infoLog);
        std::cout << "Vertex Shader ----------------------------------------" << std::endl;
        std::cout << infoLog << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }

}

void Shader::checkCompilationFragmentShader() const
{
    int succes;
    char infoLog[512];

    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &succes);
    if(!succes)
    {
        glGetShaderInfoLog(fragmentShaderID, sizeof(infoLog), NULL, infoLog);
        std::cout << "Fragment Shader --------------------------------------" << std::endl;
        std::cout << infoLog << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }
}

void Shader::checkLinkingProgram() const
{
    int succes;
    char infoLog[512];

    glGetProgramiv(programID, GL_LINK_STATUS, &succes);
    if(!succes)
    {
        glGetProgramInfoLog(programID, sizeof(infoLog), NULL, infoLog);
        std::cout << "Shader Program ---------------------------------------" << std::endl;
        std::cout << infoLog << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }
}

void Shader::use() const
{
    glUseProgram(programID);
}

void Shader::setMat4(int location, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::setFloat(int location, float num) const
{
    glUniform1f(location, num);
}

int Shader::getID() const
{
    return programID;
}