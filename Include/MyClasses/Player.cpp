#include "Player.hpp"



Player::Player()
	:hp(100), dmg(10), immunityTimer(sf::Clock()), generalTimer(sf::Clock()), pos(sf::Vector3f(0,1,0)), cam(Camera()) 
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
	pos += cam.walkDirection * generalTimer.getElapsedTime().asSeconds() * 10.0f;
	generalTimer.restart();
}

void Player::updateGunPos()
{
	static float pi	= (float)3.14159265359;
	float alpha = cam.rot.x / (2 * pi);
	float beta	= -cam.rot.y / (2 * pi);
	gunPos = cam.pointToLookAt;
	gunPos.x += 0.25 + 3* -cos(alpha)*cos(beta);
	gunPos.y += 0.25 + 3*-sin(beta);
	gunPos.z += 0.25 + 3*-cos(beta)*sin(alpha);
}