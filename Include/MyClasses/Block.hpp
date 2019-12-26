#pragma once
#include <SFML/Graphics.hpp>

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