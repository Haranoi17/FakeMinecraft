#include "Enemy.hpp"


Enemy::Enemy()
{
	directionChangeTimer = sf::Clock();

	hp = 100;
	dmg = 10;
	speed = 5;
}


Enemy::~Enemy()
{
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

void Enemy::walk() 
{
}