#pragma once

#include "SFML/Graphics.hpp"

class Enemy
{
public:

	sf::Vector3f position;
	sf::Clock directionChangeTimer;

	int hp;
	int dmg;
	float speed;
	sf::Vector3f walkDir;

	Enemy();
	~Enemy();

	void takeDmg(int dmg);
	void walk();
};

