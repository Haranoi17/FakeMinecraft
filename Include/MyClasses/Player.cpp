#include "Player.hpp"
#include <math.h>



Player::Player(const World& world)
	:	hp(100), dmg(10), immunityTimer(sf::Clock()), generalTimer(sf::Clock()), fallTimer(sf::Clock()), 
		pos(sf::Vector3f(world.dimentions.x/2, world.dimentions.y/2,world.dimentions.z/2)),
	 	cam(Camera()), movePossibilityNegative(sf::Vector3f(1,1,1)), movePossibilityPositive(sf::Vector3f(1,1,1)) 
{
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

void Player::walk(const InputController& input) 
{
	//moving 
	float deltaTime = generalTimer.getElapsedTime().asSeconds();
	if(cam.walkDirection.x > 0 && movePossibilityPositive.x)
	{
		pos.x += cam.walkDirection.x * deltaTime * 10.0f;
	}
	if(cam.walkDirection.x < 0 && movePossibilityNegative.x)
	{
		pos.x += cam.walkDirection.x * deltaTime * 10.0f;
	}
	if(cam.walkDirection.z > 0 && movePossibilityPositive.z)
	{
		pos.z += cam.walkDirection.z * deltaTime * 10.0f;
	}
	if(cam.walkDirection.z < 0 && movePossibilityNegative.z)
	{
		pos.z += cam.walkDirection.z * deltaTime * 10.0f;
	}
	
	//jumping
	if(input.getKeySpace() && movePossibilityPositive.y)
	{
		pos.y += 10*generalTimer.getElapsedTime().asSeconds();
	}

	//falling
	if(movePossibilityNegative.y == 0)
	{
		fallTimer.restart();
	}
	else
	{
		pos.y -= 0.05 * fallTimer.getElapsedTime().asSeconds() * fallTimer.getElapsedTime().asSeconds();
	}
	generalTimer.restart();
}

void Player::updateGunPos()
{
	static float pi	= (float)3.14159265359;
	float alpha = cam.rot.x / (2 * pi);
	float beta	= -cam.rot.y / (2 * pi);
	gunPos = cam.pointToLookAt;
	gunPos.x += 0.25 + 3 * -cos(alpha)*cos(beta);
	gunPos.y += 0.25 + 3 * -sin(beta);
	gunPos.z += 0.25 + 3 * -cos(beta)*sin(alpha);
}

void Player::checkMovePossibility(const World& world)
{
	int x = pos.x;
	int y = pos.y;
	int z = pos.z;

	if(pos.x - floor(pos.x) < 0.5){ x = floor(pos.x); } else { x = ceil(pos.x); }
	if(pos.y - floor(pos.y) < 0.5){ y = floor(pos.y); } else { y = ceil(pos.y); }
	if(pos.z - floor(pos.z) < 0.5){ z = floor(pos.z); } else { z = ceil(pos.z); }

	if( pos.x > 1 && pos.x < world.dimentions.x - 1 && pos.y > 1 && pos.y < world.dimentions.y - 1 && pos.z > 1 && pos.z < world.dimentions.z - 1)
	{
    	if(world.blocks[x-1][y][z].type == blockType::air){ movePossibilityNegative.x = 1;} else { movePossibilityNegative.x = 0;}
    	if(world.blocks[x][y-1][z].type == blockType::air){ movePossibilityNegative.y = 1;} else { movePossibilityNegative.y = 0;}
    	if(world.blocks[x][y][z-1].type == blockType::air){ movePossibilityNegative.z = 1;} else { movePossibilityNegative.z = 0;}
    	if(world.blocks[x+1][y][z].type == blockType::air){ movePossibilityPositive.x = 1;} else { movePossibilityPositive.x = 0;}
    	if(world.blocks[x][y+1][z].type == blockType::air){ movePossibilityPositive.y = 1;} else { movePossibilityPositive.y = 0;}
    	if(world.blocks[x][y][z+1].type == blockType::air){ movePossibilityPositive.z = 1;} else { movePossibilityPositive.z = 0;}
	}
}