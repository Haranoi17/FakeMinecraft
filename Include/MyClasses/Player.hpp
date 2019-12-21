#pragma once

#include <Bullet/btBulletDynamicsCommon.h>
#include "SFML/Graphics.hpp"
#include <InputController.hpp>
#include <Camera.hpp>
#include <vector>
#include <Block.hpp>

class Player
{
public:

	btRigidBody *RigidBody;
	btScalar mass;
	btTransform trans;
	btVector3 pos;

	sf::Clock immunityTimer;
	sf::Clock generalTimer;
	int hp;
	int dmg;

	std::vector<blockType> slots;

	Player();
	~Player();

	void takeDmg(int dmg);
	void walk(const InputController&, const Camera&);
};

