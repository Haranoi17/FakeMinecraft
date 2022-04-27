#include "ResourceLoader.hpp"
#include "Utilities.hpp"

sf::Texture ResourceLoader::loadTexture(std::string_view filename)
{
    const std::filesystem::path texturePath{relativePath(texturesLocation).concat(filename)};
    
    sf::Texture newTexture{};
    newTexture.loadFromFile(texturePath);

    return newTexture;
}

Shader ResourceLoader::loadShader(std::string_view vertexShaderFilename, std::string_view fragmentShaderFilename)
{
    std::filesystem::path vertexShaderPath{relativePath(shadersLocation).concat(vertexShaderFilename)};
    std::filesystem::path fragmentShaderPath{relativePath(shadersLocation).concat(fragmentShaderFilename)};

    return Shader{vertexShaderPath, fragmentShaderPath}; 
}