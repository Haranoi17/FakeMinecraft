#include <glm/gtc/matrix_transform.hpp>

#include "Block.hpp"

Block::Block(const Vector3f& position, Block::Type type)
    : m_position(position), m_type(type)
{
}
