#pragma once

#include <SFML/Graphics.hpp>

class Vector3f : public sf::Vector3f
{
public:
	Vector3f();
	Vector3f(const Vector3f &vector);
	Vector3f(const sf::Vector3f &vector);
	Vector3f(float x, float y, float z);

	float length() const;
	Vector3f normal() const;
	void normalize();

	Vector3f operator=(const Vector3f &other);
};