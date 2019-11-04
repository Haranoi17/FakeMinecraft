#pragma once
#include <SFML/Graphics.hpp>

class Cube
{
public:
	Cube();
	Cube(float x, float y, float z);
	~Cube();

	sf::Vector3f pos;

	void draw();
};

