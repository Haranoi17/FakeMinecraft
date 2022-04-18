#include <Block.hpp>
#include <glm/gtc/matrix_transform.hpp>

Block::Block()
{
}

Block::Block(sf::Vector3f pos, blockType initType)
    : position(pos), type(initType)
{
}
