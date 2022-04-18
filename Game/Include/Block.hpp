#pragma once
#include <SFML/Graphics.hpp>
#include <glm/mat4x4.hpp>
#include <Vector3f.hpp>

enum BlockType
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
    Block(Vector3f position, BlockType type);

    BlockType m_type;
    Vector3f m_position;
};