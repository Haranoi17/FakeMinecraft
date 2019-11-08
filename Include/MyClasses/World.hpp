#pragma once

#include <SFML/Graphics.hpp>

class World
{
public:
    World(int seed);
    ~World();

    int width;
    int depth;
    int ***heights;
    sf::Vector3i ***blockCoords;

private:

};