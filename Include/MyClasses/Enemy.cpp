#include "Enemy.hpp"


Enemy::Enemy()
{
	this->mass = btScalar(1);
	this->enemyRigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(this->mass, new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 5, 0))), new btBoxShape(btVector3(0.5,0.5,0.5)), btVector3(1, 1, 1)));
	this->directionChangeTimer = sf::Clock();

	this->hp = 100;
	this->dmg = 10;
	this->speed = 5;
}


Enemy::~Enemy()
{
}


void Enemy::takeDmg(int dmg)
{
	if (this->hp > 0)
	{
		this->hp -= dmg;
	}

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

bool Enemy::searchForPlayer(btRigidBody *playerRigidBody)
{
	btVector3 towardsPlayer = btVector3(playerRigidBody->getCenterOfMassPosition().getX() - this->enemyRigidBody->getCenterOfMassPosition().getX(), playerRigidBody->getCenterOfMassPosition().getY() - this->enemyRigidBody->getCenterOfMassPosition().getY(), playerRigidBody->getCenterOfMassPosition().getZ() - this->enemyRigidBody->getCenterOfMassPosition().getZ());

	if (towardsPlayer.length() < 10) 
	{
		towardsPlayer.safeNormalize();
		this->enemyRigidBody->applyCentralForce(towardsPlayer);
		return true;
	}
	return false;
}

void Enemy::walk() 
{
}