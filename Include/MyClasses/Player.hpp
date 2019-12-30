#pragma once

#include "SFML/Graphics.hpp"
#include <InputController.hpp>
#include <Camera.hpp>
#include <vector>
#include <Block.hpp>
#include <World.hpp>

class World;

class Player
{
public:

	sf::Vector3f pos;
	sf::Vector3f movePossibilityPositive;
	sf::Vector3f movePossibilityNegative;
	sf::Vector3f gunPos;


	sf::Clock immunityTimer;
	sf::Clock generalTimer;
	float fallingTime;
	float jumpingTime;
	bool jump;
	bool jumpPrev;
	int hp;
	int dmg;

	std::vector<blockType> slots;
	Camera cam;

	Player();
	Player(const World&);
	~Player();

 	void checkMovePossibility(const World&);
	void takeDmg(int dmg);
	void walk(const InputController&, const World&, float);
	void updateGunPos();
};

