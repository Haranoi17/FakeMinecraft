#include <Block.hpp>
#include <glm/gtc/matrix_transform.hpp>

Block::Block(const Vector3f& position, BlockType type)
    : m_position(position), m_type(type)
{
}
