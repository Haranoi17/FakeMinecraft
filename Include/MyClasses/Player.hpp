#pragma once

#include "SFML/Graphics.hpp"
#include <InputController.hpp>
#include <Camera.hpp>
#include <vector>
#include <Block.hpp>

class Player
{
public:

	sf::Vector3f pos;
	sf::Vector3f gunPos;

	sf::Clock immunityTimer;
	sf::Clock generalTimer;
	int hp;
	int dmg;

	std::vector<blockType> slots;
	Camera cam;

	Player();
	~Player();

	void takeDmg(int dmg);
	void walk(const InputController&);
	void updateGunPos();
};

