#pragma once

#include <Bullet/btBulletDynamicsCommon.h>
#include "SFML/Graphics.hpp"
#include <InputController.hpp>
#include <Camera.hpp>

class Player
{
public:

	btRigidBody *RigidBody;
	btScalar mass;
	btTransform trans;

	sf::Clock immunityTimer;
	int hp;
	int dmg;

	Player();
	~Player();

	void takeDmg(int dmg);
	void walk(const InputController&, const Camera&);
};

