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

	Vector3f pos;
	Vector3f movePossibilityPositive;
	Vector3f movePossibilityNegative;
	Vector3f gunPos;


	sf::Clock immunityTimer;
	sf::Clock generalTimer;
	float fallingTime;
	float jumpingTime;
	bool jump;
	bool jumpPrev;
	int hp;
	int dmg;

	std::vector<BlockType> slots;
	Camera cam;

	Player();
	Player(const World&);
	~Player();

 	void checkMovePossibility(const World&);
	void takeDmg(int dmg);
	void walk(const InputController&, const World&, float);
	void updateGunPos();
};

