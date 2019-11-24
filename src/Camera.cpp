#include "Camera.hpp"
#include <vectorOperations.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	this->pos = sf::Vector3f(0, 3, -5);
	this->rot = sf::Vector2f();
	this->pointToLookAt = pos;
	this->pointToLookAt.z -= 1;
	this->lookDirection = this->pointToLookAt - this->pos;
	this->lookDirectionFlat = this->lookDirection;
	this->walkDirection = sf::Vector3f();
}

Camera::~Camera()
{
}

void Camera::updateCameraPosition() 
{
	static float pi	= (float)3.14159265359;
	static float r = 2;
	float alpha = this->rot.x / (2 * pi);
	float beta	= -this->rot.y / (2 * pi);

	this->pos = this->pointToLookAt - this->lookDirection;

	this->pos.x += r * cos(alpha)*cos(beta);
	this->pos.y += r * sin(beta);
	this->pos.z += r * cos(beta)*sin(alpha);

	this->updateLookDirectionCallback();
	this->updateSideDirectionCallback();
}

void Camera::updateCameraRotation(sf::Vector2i d, float mouseSpeed) 
{
	static bool canLookUp = 1;
	static bool canLookDown = 1;
	float pi = (float)3.14159265359;

	float radY = this->rot.y / (2 * pi);

	this->rot.x += (float)d.x * mouseSpeed;
	
	if (radY > pi/2 - 0.1) //less than pi/2
	{
		canLookUp = 0;
	}
	else 
	{
		canLookUp = 1;
	}
	if (radY < -pi/2 + 0.1) //less than pi/2
	{
		canLookDown = 0;
	}
	else
	{
		canLookDown = 1;
	}

	if (canLookUp && d.y > 0)
	{
		this->rot.y += (float)d.y * mouseSpeed;
	}
	if (canLookDown && d.y < 0)
	{
		this->rot.y += (float)d.y * mouseSpeed;
	}

	this->updateLookDirectionCallback();
	this->updateSideDirectionCallback();
}

void Camera::updateLookDirectionCallback() 
{
	this->lookDirection = this->pointToLookAt - this->pos;
	normalize(&this->lookDirection);
	this->lookDirectionFlat = this->lookDirection;
	this->lookDirectionFlat.y = 0;
	normalize(&this->lookDirectionFlat);
}

void Camera::updateSideDirectionCallback() 
{
	this->sideDirection = sf::Vector3f(-this->lookDirection.z, 0, this->lookDirection.x); //sneaky method all adjacent vectors on plane be like [(a,b), (-b,a)]
	normalize(&this->sideDirection);
}

void Camera::updatePointToLookAtPosition(sf::Vector3f newPos) 
{
	this->pointToLookAt = newPos;

	//some trivial transformations
	this->pointToLookAt.y += 1;
}

void Camera::updateWalkDirection() 
{
	sf::Vector3f resultant = sf::Vector3f(0, 0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		 resultant += lookDirectionFlat;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		resultant -= lookDirectionFlat;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		resultant -= sideDirection;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		resultant += sideDirection;
	}
	normalize(&resultant);
	this->walkDirection = resultant;
}

glm::mat4 Camera::moveCamera() 
{
	// gluLookAt(pos.x, pos.y, pos.z, pointToLookAt.x, pointToLookAt.y, pointToLookAt.z, 0, 1, 0);
	// glm::mat4 temp = glm::lookAt(glm::vec3(pos.x, pos.y, pos.z), glm::vec3(pointToLookAt.x, pointToLookAt.y, pointToLookAt.z), glm::vec3(0,1,0));
	// float buff[16];
	// int index = 0;
	// for(int i = 0; i < 4; i++)
	// {
	// 	for(int j = 0; j < 4; j++)
	// 	{
	// 		buff[index++] = temp[i][j];
	// 	}
	// }
	
	
	return glm::lookAt(glm::vec3(pos.x, pos.y, pos.z), glm::vec3(pointToLookAt.x, pointToLookAt.y, pointToLookAt.z), glm::vec3(0,1,0));
}