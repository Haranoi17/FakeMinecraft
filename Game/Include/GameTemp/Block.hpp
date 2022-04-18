#pragma once
#include <SFML/Graphics.hpp>
#include <glm/mat4x4.hpp>

enum blockType
{
    air,
    dirt,
    stone,
    wood,
    leaves
};

class Block
{
    public:
    Block();
    Block(sf::Vector3f, blockType);

    blockType type;
    sf::Vector3f position;
};