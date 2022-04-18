#include <Block.hpp>
#include <glm/gtc/matrix_transform.hpp>

Block::Block(Vector3f pos, BlockType initType)
    : m_position(pos), m_type(initType)
{
}
