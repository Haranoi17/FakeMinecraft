#include "Player.hpp"



Player::Player()
{
	this->mass = btScalar(1);
	this->playerRigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(this->mass, new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 2, 0))), new btBoxShape(btVector3(0.5,0.5,0.5)), btVector3(1, 1, 1)));
	
	this->hp = 100;
	this->dmg = 10;
	this->immunityTimer = sf::Clock();
}


Player::~Player()
{
}

void Player::takeDmg(int dmg) 
{
	if (this->immunityTimer.getElapsedTime().asSeconds() > 3) 
	{	
		if (this->hp > 0) 
		{
			this->hp -= dmg;
		}

		if (this->hp < 0) 
		{
			this->hp = 0;
		}
		this->immunityTimer.restart();
	}
}

void Player::walk(btVector3 walkDirection) 
{
	static bool blockSpace = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->playerRigidBody->applyCentralForce(btVector3(walkDirection.getX() * 20, 0, walkDirection.getZ() * 20));
	}
	else
	{
		this->playerRigidBody->applyCentralForce(btVector3(0, 0, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !blockSpace)
	{
		this->playerRigidBody->applyCentralImpulse(btVector3(0, 8, 0));
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