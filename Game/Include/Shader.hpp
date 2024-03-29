#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include <fstream>
#include <filesystem>

class Shader
{
public:
    Shader() = default;
    Shader(const std::filesystem::path& fragmentShaderPath , const std::filesystem::path& vertexShaderPath);

    void use() const;
    void setMat4(int, const glm::mat4&) const;
    void setFloat(int, float) const;
 
    int getID() const;

    int projectionLoc;
    int viewLoc;
    int modelLoc;
private:

    void checkCompilationVertexShader() const;
    void checkCompilationFragmentShader() const;
    void checkLinkingProgram() const;

    int programID;
    int vertexShaderID;
    int fragmentShaderID;
};