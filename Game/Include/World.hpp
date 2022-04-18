#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Block.hpp>
#include <Player.hpp>

class Player;

class World
{
    public:
    World();
    ~World();
    void alocateMemory();
    void generateTerrain();
    void generateTrees();
    void fillBlockTypes();
    void prepareBlocksWithAirTouch(const Player& player);
    void prepareToDraw(const Player& player);

    bool checkAir(const Vector3f&) const;
    sf::Vector3i dimentions;
    float **heights;
    Block ***blocks;

    std::vector<Block*> blocksWithAirTouch;
    std::vector<Block*> blocksToDraw;
    std::vector<Block*> blocksNextToPlayer;

    int ammountToDraw;
};