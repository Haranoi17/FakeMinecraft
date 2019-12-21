#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Bullet/btBulletCollisionCommon.h>
#include <Block.hpp>

class World
{
    public:
    World(int);
    ~World();
    void alocateMemory();
    void fillBlockTypes();
    void prepareToDraw();

    bool checkAir(btVector3);
    btVector3 dimentions;
    Block ***blocks;

    std::vector<Block> blocksToDraw;
    int ammountToDraw;
};