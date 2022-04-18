#include <Vector3f.hpp>
#include <math.h>

Vector3f::Vector3f()
	: sf::Vector3f{0.0f, 0.0f, 0.0f}
{
}

Vector3f::Vector3f(const Vector3f &vector)
	: sf::Vector3f{vector.x, vector.y, vector.z}
{
}

Vector3f::Vector3f(const sf::Vector3f &vector)
	: sf::Vector3f{vector.x, vector.y, vector.z}
{
}

Vector3f::Vector3f(float x, float y, float z)
	: sf::Vector3f{x, y, z}
{
}

float Vector3f::length() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3f Vector3f::normal() const
{
	const float len = length();
	Vector3f normalized{x, y, z};
	
	if (len)
	{
		normalized /= len;
	}

	return normalized;
}

void Vector3f::normalize()
{
	(*this) = normal();
}

Vector3f Vector3f::operator=(const Vector3f &other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}