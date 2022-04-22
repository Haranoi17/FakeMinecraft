#pragma once
#include <SFML/Graphics.hpp>
#include <glm/mat4x4.hpp>
#include <Vector3f.hpp>

enum class BlockType
{
    Air,
    Dirt,
    Stone,
    Wood,
    Leaves
};

class Block
{
    public:
    Block() = default;
    Block(const Vector3f& position, BlockType type);

    BlockType m_type;
    Vector3f m_position;
};