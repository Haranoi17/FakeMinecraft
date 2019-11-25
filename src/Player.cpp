#include "Player.hpp"



Player::Player()
{
	mass = btScalar(1);
	RigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(mass, new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 2, 0))), new btBoxShape(btVector3(0.5,0.5,0.5)), btVector3(1, 1, 1)));
	
	hp = 100;
	dmg = 10;
	immunityTimer = sf::Clock();
}


Player::~Player()
{
}

void Player::takeDmg(int dmg) 
{
	if (immunityTimer.getElapsedTime().asSeconds() > 3) 
	{	
		if (hp > 0) 
		{
			hp -= dmg;
		}

		if (hp < 0) 
		{
			hp = 0;
		}
		immunityTimer.restart();
	}
}

void Player::walk(btVector3 walkDirection) 
{
	static bool blockSpace = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		RigidBody->applyCentralForce(btVector3(walkDirection.getX() * 20, 0, walkDirection.getZ() * 20));
	}
	else
	{
		RigidBody->applyCentralForce(btVector3(0, 0, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !blockSpace)
	{
		RigidBody->applyCentralImpulse(btVector3(0, 8, 0));
		blockSpace = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && blockSpace)
	{
		blockSpace = true;
	}
	else
	{
		blockSpace = false;
	}
}