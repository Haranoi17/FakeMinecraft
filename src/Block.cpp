#include <Block.hpp>

Block::Block()
{
}

Block::Block(btVector3 pos, blockType initType)
    : position(pos), type(initType)
{
}
