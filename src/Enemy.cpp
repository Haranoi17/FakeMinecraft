#include "Enemy.hpp"


Enemy::Enemy()
{
	mass = btScalar(1);
	RigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(mass, new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 5, 0))), new btBoxShape(btVector3(0.5,0.5,0.5)), btVector3(1, 1, 1)));
	directionChangeTimer = sf::Clock();

	hp = 100;
	dmg = 10;
	speed = 5;
}


Enemy::~Enemy()
{
	RigidBody->~btRigidBody();
	delete RigidBody;
}


void Enemy::takeDmg(int dmg)
{
	if (hp > 0)
	{
		hp -= dmg;
	}

	if (hp <= 0)
	{
		hp = 0;
	}
}

bool Enemy::searchForPlayer(const btRigidBody *playerRigidBody)
{
	btVector3 towardsPlayer = btVector3(playerRigidBody->getCenterOfMassPosition().getX() - RigidBody->getCenterOfMassPosition().getX(), playerRigidBody->getCenterOfMassPosition().getY() - RigidBody->getCenterOfMassPosition().getY(), playerRigidBody->getCenterOfMassPosition().getZ() - RigidBody->getCenterOfMassPosition().getZ());

	if (towardsPlayer.length() < 10) 
	{
		towardsPlayer.safeNormalize();
		RigidBody->applyCentralForce(towardsPlayer);
		return true;
	}
	return false;
}

void Enemy::walk() 
{
}