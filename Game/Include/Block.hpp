#pragma once
#include <SFML/Graphics.hpp>
#include <glm/mat4x4.hpp>

#include "Vector3f.hpp"

class Block
{
public:
    enum class Type
    {
        Air,
        Dirt,
        Stone,
        Wood,
        Leaves
    };

    Block() = default;
    Block(const Vector3f &position, Type type);

    Type m_type;
    Vector3f m_position;
};