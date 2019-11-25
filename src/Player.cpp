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

void Player::walk(const InputController& input, const Camera& cam) 
{
	static bool blockSpace = false;
	btVector3 direction = btVector3(cam.walkDirection.x, cam.walkDirection.y, cam.walkDirection.z);

	if ( input.getKeyW() || input.getKeyS() || input.getKeyA() || input.getKeyD())
	{
		trans = RigidBody->getWorldTransform();
		trans.getOrigin() += direction;
		RigidBody->setWorldTransform(trans);
		RigidBody->getMotionState()->setWorldTransform(trans);
	}
	if ( input.getKeySpace() && !blockSpace)
	{
		blockSpace = true;
	}
	else if ( input.getKeySpace() && blockSpace)
	{
		blockSpace = true;
	}
	else
	{
		blockSpace = false;
	}

}

