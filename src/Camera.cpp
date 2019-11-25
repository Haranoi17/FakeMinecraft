#include "Camera.hpp"
#include <vectorOperations.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	pos = sf::Vector3f(0, 3, -5);
	rot = sf::Vector2f();
	pointToLookAt = pos;
	pointToLookAt.z -= 1;
	lookDirection = pointToLookAt - pos;
	lookDirectionFlat = lookDirection;
	walkDirection = sf::Vector3f();
}

Camera::~Camera()
{
}

void Camera::updateCameraPosition() 
{
	static float pi	= (float)3.14159265359;
	static float r = 2;
	float alpha = rot.x / (2 * pi);
	float beta	= -rot.y / (2 * pi);

	pos = pointToLookAt - lookDirection;

	pos.x += r * cos(alpha)*cos(beta);
	pos.y += r * sin(beta);
	pos.z += r * cos(beta)*sin(alpha);

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

void Camera::updateCameraRotation(sf::Vector2i d, float mouseSpeed) 
{
	static bool canLookUp = 1;
	static bool canLookDown = 1;
	float pi = (float)3.14159265359;

	float radY = rot.y / (2 * pi);

	rot.x += (float)d.x * mouseSpeed;
	
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
		rot.y += (float)d.y * mouseSpeed;
	}
	if (canLookDown && d.y < 0)
	{
		rot.y += (float)d.y * mouseSpeed;
	}

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

void Camera::updateLookDirectionCallback() 
{
	lookDirection = pointToLookAt - pos;
	normalize(&lookDirection);
	lookDirectionFlat = lookDirection;
	lookDirectionFlat.y = 0;
	normalize(&lookDirectionFlat);
}

void Camera::updateSideDirectionCallback() 
{
	sideDirection = sf::Vector3f(-lookDirection.z, 0, lookDirection.x); //sneaky method all adjacent vectors on plane be like [(a,b), (-b,a)]
	normalize(&sideDirection);
}

void Camera::updatePointToLookAtPosition(sf::Vector3f newPos) 
{
	pointToLookAt = newPos;

	//some trivial transformations
	pointToLookAt.y += 1;
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
	walkDirection = resultant;
}

void Camera::moveCamera() 
{
	gluLookAt(pos.x, pos.y, pos.z, pointToLookAt.x, pointToLookAt.y, pointToLookAt.z, 0, 1, 0);
}