#pragma once

#include <SFML/Graphics.hpp>
#include "InputController.hpp"
#include "Camera.hpp"
#include "vector"
#include "Block.hpp"
#include "World.hpp"

class World;

class Player
{
public:
	Vector3f position;
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

	std::vector<Block::Type> slots;
	Camera cam;

	Player();
	Player(const World&);
	~Player();

 	void checkMovePossibility(const World& world);
	void takeDmg(int dmg);
	void walk(const InputController& inputController, const World& world, float dt);
	void updateGunPos();
};

