#pragma once

#include <Bullet/btBulletDynamicsCommon.h>
#include "SFML/Graphics.hpp"

class Player
{
public:

	btRigidBody *RigidBody;
	btTransform	 trans;
	btScalar mass;

	sf::Clock immunityTimer;
	int hp;
	int dmg;

	Player();
	~Player();

	void takeDmg(int dmg);
	void walk(btVector3 walkDirection);
};

