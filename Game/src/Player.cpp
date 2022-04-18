#include "Player.hpp"
#include <math.h>
#include <Vector3f.hpp>


Player::Player(const World& world)
	:	hp(100), dmg(10), immunityTimer(sf::Clock()), generalTimer(sf::Clock()), fallingTime(0), jumpingTime(0), jump(false), jumpPrev(false),
		position(Vector3f(world.dimentions.x/2 + 3, 0, world.dimentions.z/2)),
	 	cam(Camera()), movePossibilityNegative(Vector3f(1,1,1)), movePossibilityPositive(Vector3f(1,1,1)) 
{
	position.y = world.heights[(int)position.x][(int)position.z] + 10;
}

Player::Player()
	:	hp(100), dmg(10), immunityTimer(sf::Clock()), generalTimer(sf::Clock()), fallingTime(0), jumpingTime(0), jump(false), jumpPrev(false),
		position(Vector3f(10,10,10)),
	 	cam(Camera()), movePossibilityNegative(Vector3f(1,1,1)), movePossibilityPositive(Vector3f(1,1,1)) 
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

void Player::walk(const InputController& input, const World& world, float dt) 
{	
	static Vector3f prevPos = position;
	
		
	checkMovePossibility(world);
	if(movePossibilityNegative.x || movePossibilityNegative.z || movePossibilityPositive.x || movePossibilityPositive.z)
	{
		prevPos = position;
	}
	//moving 
	if(cam.m_front.x > 0 && movePossibilityPositive.x)
	{
		position.x += cam.m_front.x * dt * 5.0f;
	}
	if(cam.m_front.x < 0 && movePossibilityNegative.x)
	{
		position.x += cam.m_front.x * dt * 5.0f;
	}
	if(cam.m_front.z > 0 && movePossibilityPositive.z)
	{
		position.z += cam.m_front.z * dt * 5.0f;
	}
	if(cam.m_front.z < 0 && movePossibilityNegative.z)
	{
		position.z += cam.m_front.z * dt * 5.0f;
	}
	//jumping
	if(input.getKeySpace())
	{
		jump = true;
	}

	if(jump && movePossibilityPositive.y)
	{
		jumpingTime += dt/20;
		position.y += 1/(30 + jumpingTime);
	}
	else
	{
		jumpingTime = 0;
	}

	//falling
	if(movePossibilityNegative.y)
	{
		fallingTime += dt/20;
		position.y -= pow(fallingTime*5, 2);
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
		position = prevPos;
	}

	jumpPrev = jump;
	generalTimer.restart();
}

void Player::updateGunPos()
{
	static float pi	= (float)3.14159265359;
	float alpha = cam.m_rotation.x / (2 * pi);
	float beta	= -cam.m_rotation.y / (2 * pi);
	float r = 2.1;
	gunPos = cam.m_pointToLookAt;
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
	int x = position.x;
	int y = position.y;
	int z = position.z;
	std::vector<Block*> blocks;
	
 	int leftBound;
    int rightBound;
    int topBound;
    int bottomBound;
    int frontBound;
    int backBound;

	int r = 5;
    if(position.x - r <= 1){leftBound = 0;} else {leftBound = position.x - r;}
    if(position.y - r <= 1){bottomBound = 0;} else {bottomBound = position.y - r;}
    if(position.z - r <= 1){backBound = 0;} else {backBound = position.z - r;}

    if(position.x + r >= world.dimentions.x - 1){rightBound = world.dimentions.x;} else {rightBound = position.x + r;}
    if(position.y + r >= world.dimentions.y - 1){topBound = world.dimentions.y;} else {topBound = position.y + r;}
    if(position.z + r >= world.dimentions.z - 1){frontBound = world.dimentions.z;} else {frontBound = position.z + r;}

    for(int i = leftBound; i < rightBound; i++)
    {
        for(int j = bottomBound; j < topBound; j++)
        {
            for(int k = backBound; k < frontBound; k++)
            {
				if(world.blocks[i][j][k].m_type != BlockType::Air)
				{
					blocks.push_back(&world.blocks[i][j][k]);
				}
			}
		}
	}
	movePossibilityNegative = Vector3f(1,1,1);
	movePossibilityPositive = Vector3f(1,1,1);
	for(auto *block : blocks)
	{
		Vector3f middle = Vector3f(block->m_position.x + 0.25, block->m_position.y + 0.25, block->m_position.z + 0.25);
		float left = block->m_position.x - 0.5;
		float right = block->m_position.x + 0.5;
		float bottom = block->m_position.y - 0.5;
		float top = block->m_position.y + 0.5;
		float back = block->m_position.z - 0.5;
		float front = block->m_position.z + 0.5;

		float PLeft = position.x -0.2;
		float PRight = position.x + 0.2;
		float PBottom = position.y - 0.5;
		float PTop = position.y + 0.5;
		float PBack = position.z - 0.2;
		float PFront = position.z + 0.2;
		
		bool intersects = false;
		if(Vector3f{(position - middle)}.length() < 5)
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
			if(middle.y - position.y > 0)
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
}