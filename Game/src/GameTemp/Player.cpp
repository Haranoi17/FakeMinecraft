#include "Player.hpp"
#include <math.h>
#include <vectorOperations.hpp>


Player::Player(const World& world)
	:	hp(100), dmg(10), immunityTimer(sf::Clock()), generalTimer(sf::Clock()), fallingTime(0), jumpingTime(0), jump(false), jumpPrev(false),
		pos(sf::Vector3f(world.dimentions.x/2 + 3, 0, world.dimentions.z/2)),
	 	cam(Camera()), movePossibilityNegative(sf::Vector3f(1,1,1)), movePossibilityPositive(sf::Vector3f(1,1,1)) 
{
	pos.y = world.heights[(int)pos.x][(int)pos.z] + 10;
}

Player::Player()
	:	hp(100), dmg(10), immunityTimer(sf::Clock()), generalTimer(sf::Clock()), fallingTime(0), jumpingTime(0), jump(false), jumpPrev(false),
		pos(sf::Vector3f(10,10,10)),
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

void Player::walk(const InputController& input, const World& world, float deltaTime) 
{	
	static sf::Vector3f prevPos = pos;
	
		
	checkMovePossibility(world);
	if(movePossibilityNegative.x || movePossibilityNegative.z || movePossibilityPositive.x || movePossibilityPositive.z)
	{
		prevPos = pos;
	}
	//moving 
	if(cam.walkDirection.x > 0 && movePossibilityPositive.x)
	{
		pos.x += cam.walkDirection.x * deltaTime * 5.0f;
	}
	if(cam.walkDirection.x < 0 && movePossibilityNegative.x)
	{
		pos.x += cam.walkDirection.x * deltaTime * 5.0f;
	}
	if(cam.walkDirection.z > 0 && movePossibilityPositive.z)
	{
		pos.z += cam.walkDirection.z * deltaTime * 5.0f;
	}
	if(cam.walkDirection.z < 0 && movePossibilityNegative.z)
	{
		pos.z += cam.walkDirection.z * deltaTime * 5.0f;
	}
	//jumping
	if(input.getKeySpace())
	{
		jump = true;
	}

	if(jump && movePossibilityPositive.y)
	{
		jumpingTime += deltaTime/20;
		pos.y += 1/(30 + jumpingTime);
	}
	else
	{
		jumpingTime = 0;
	}

	//falling
	if(movePossibilityNegative.y)
	{
		fallingTime += deltaTime/20;
		pos.y -= pow(fallingTime*5, 2);
	}              
	else
	{
		jump = false;
		jumpingTime = 0;
		fallingTime = 0;
	}
	
	checkMovePossibility(world);
	if(!movePossibilityNegative.x && !movePossibilityNegative.z && !movePossibilityPositive.x && !movePossibilityPositive.z)
	{
		pos = prevPos;
	}

	jumpPrev = jump;
	generalTimer.restart();
}

void Player::updateGunPos()
{
	static float pi	= (float)3.14159265359;
	float alpha = cam.rot.x / (2 * pi);
	float beta	= -cam.rot.y / (2 * pi);
	float r = 2.1;
	gunPos = cam.pointToLookAt;
	gunPos.x += 0.25 + r * -cos(alpha)*cos(beta);
	gunPos.y += 0.25 + r * -sin(beta);
	gunPos.z += 0.25 + r * -cos(beta)*sin(alpha);
}

void Player::checkMovePossibility(const World& world)
{
	bool checkXP = true;
	bool checkYP = true;
	bool checkZP = true;
	bool checkXN = true;
	bool checkYN = true;
	bool checkZN = true;
	int x = pos.x;
	int y = pos.y;
	int z = pos.z;
	std::vector<Block*> blocks;
	
 	int leftBound;
    int rightBound;
    int topBound;
    int bottomBound;
    int frontBound;
    int backBound;

	int r = 5;
    if(pos.x - r <= 1){leftBound = 0;} else {leftBound = pos.x - r;}
    if(pos.y - r <= 1){bottomBound = 0;} else {bottomBound = pos.y - r;}
    if(pos.z - r <= 1){backBound = 0;} else {backBound = pos.z - r;}

    if(pos.x + r >= world.dimentions.x - 1){rightBound = world.dimentions.x;} else {rightBound = pos.x + r;}
    if(pos.y + r >= world.dimentions.y - 1){topBound = world.dimentions.y;} else {topBound = pos.y + r;}
    if(pos.z + r >= world.dimentions.z - 1){frontBound = world.dimentions.z;} else {frontBound = pos.z + r;}

    for(int i = leftBound; i < rightBound; i++)
    {
        for(int j = bottomBound; j < topBound; j++)
        {
            for(int k = backBound; k < frontBound; k++)
            {
				if(world.blocks[i][j][k].type != blockType::air)
				{
					blocks.push_back(&world.blocks[i][j][k]);
				}
			}
		}
	}
	movePossibilityNegative = sf::Vector3f(1,1,1);
	movePossibilityPositive = sf::Vector3f(1,1,1);
	for(auto *block : blocks)
	{
		sf::Vector3f middle = sf::Vector3f(block->position.x + 0.25, block->position.y + 0.25, block->position.z + 0.25);
		float left = block->position.x - 0.5;
		float right = block->position.x + 0.5;
		float bottom = block->position.y - 0.5;
		float top = block->position.y + 0.5;
		float back = block->position.z - 0.5;
		float front = block->position.z + 0.5;

		float PLeft = pos.x -0.2;
		float PRight = pos.x + 0.2;
		float PBottom = pos.y - 0.5;
		float PTop = pos.y + 0.5;
		float PBack = pos.z - 0.2;
		float PFront = pos.z + 0.2;
		
		bool intersects = false;
		if(vec3Length(pos - middle) < 5)
		{
			if(PRight > left && PLeft < right && PTop > bottom && PBottom < top && PFront > back && PBack < front)
			{
				intersects = true;
			}
		}
		
		if(intersects)
		{

			if(checkYN && PBottom < top && PTop > top)
			{
				movePossibilityNegative.y = 0;
				checkYN = false;
			}
			if(checkYP && PTop > bottom && PBottom < bottom)
			{
				movePossibilityPositive.y = 0;
				checkYP = false;
			}
			if(middle.y - pos.y > 0)
			{
				if(checkXP && PRight > left && PLeft < left)
				{
					movePossibilityPositive.x = 0;
					checkXP = false;
				}
				if(checkZP && PFront > back && PBack < back)
				{
					movePossibilityPositive.z = 0;
					checkZP = false;
				}

				if(checkXN && PLeft < right && PRight > right)
				{
					movePossibilityNegative.x = 0;
					checkXN = false;
				}
				if(checkZN && PBack < front && PFront > front)
				{
					movePossibilityNegative.z = 0;
					checkZN = false;
				}
			}
		}
	}
	// if(pos.x - floor(pos.x) < 0.5){ x = floor(pos.x); } else { x = ceil(pos.x); }
	// if(pos.y - floor(pos.y) < 0.5){ y = floor(pos.y); } else { y = ceil(pos.y); }
	// if(pos.z - floor(pos.z) < 0.5){ z = floor(pos.z); } else { z = ceil(pos.z); }

	// if( pos.x > 1 && pos.x < world.dimentions.x - 1 && pos.y > 1 && pos.y < world.dimentions.y - 1 && pos.z > 1 && pos.z < world.dimentions.z - 1)
	// {
    // 	if(world.blocks[x-1][y][z].type == blockType::air){ movePossibilityNegative.x = 1;} else { movePossibilityNegative.x = 0;}
    // 	if(world.blocks[x][y-1][z].type == blockType::air){ movePossibilityNegative.y = 1;} else { movePossibilityNegative.y = 0;}
    // 	if(world.blocks[x][y][z-1].type == blockType::air){ movePossibilityNegative.z = 1;} else { movePossibilityNegative.z = 0;}
    // 	if(world.blocks[x+1][y][z].type == blockType::air){ movePossibilityPositive.x = 1;} else { movePossibilityPositive.x = 0;}
    // 	if(world.blocks[x][y+1][z].type == blockType::air){ movePossibilityPositive.y = 1;} else { movePossibilityPositive.y = 0;}
    // 	if(world.blocks[x][y][z+1].type == blockType::air){ movePossibilityPositive.z = 1;} else { movePossibilityPositive.z = 0;}
	// }
}