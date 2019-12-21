#include <Block.hpp>

Block::Block()
{
}

Block::Block(sf::Vector3f pos, blockType initType)
    : position(pos), type(initType)
{
}
