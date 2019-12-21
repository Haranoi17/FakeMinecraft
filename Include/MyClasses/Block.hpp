#pragma once
#include <Bullet/btBulletCollisionCommon.h>

enum blockType
{
    air,
    dirt,
    stone,
};

class Block
{
    public:
    Block();
    Block(btVector3, blockType);

    blockType type;
    btVector3 position;
};