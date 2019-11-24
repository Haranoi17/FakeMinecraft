#pragma once

#include <Bullet/btBulletDynamicsCommon.h>
#include "SFML/Graphics.hpp"

class Enemy
{
public:

	btRigidBody *RigidBody;
	btScalar mass;
	sf::Clock directionChangeTimer;

	int hp;
	int dmg;
	float speed;
	btVector3 walkDir;

	Enemy();
	~Enemy();

	void takeDmg(int dmg);
	bool searchForPlayer(btRigidBody *playerRigidBody);
	void walk();
};

