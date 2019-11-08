#pragma once
#include <SFML/Graphics.hpp>

class Cube
{
public:
	Cube();
	Cube(int x, int y, int z);
	~Cube();

	sf::Vector3i pos;
	void draw();
};

