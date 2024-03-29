#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string_view>

#include "Shader.hpp"

class ResourceLoader
{
    inline static constexpr std::string_view texturesLocation{"/resources/textures/"};
    inline static constexpr std::string_view shadersLocation{"/resources/shaders/"};

public:
    sf::Texture loadTexture(std::string_view filename);
    Shader loadShader(std::string_view fragmentShaderFilename, std::string_view vertexShaderFilename);
};