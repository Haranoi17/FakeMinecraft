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

void Camera::updateCameraRotation(const InputController &input, float mouseSpeed) 
{
	static bool canLookUp = 1;
	static bool canLookDown = 1;
	float pi = (float)3.14159265359;

	float radY = rot.y / (2 * pi);

	rot.x += (float)input.getMouseDeltaX() * mouseSpeed;
	
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

	if (canLookUp && input.getMouseDeltaY() > 0)
	{
		rot.y += (float)input.getMouseDeltaY() * mouseSpeed;
	}
	if (canLookDown && input.getMouseDeltaY() < 0)
	{
		rot.y += (float)input.getMouseDeltaY() * mouseSpeed;
	}

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

void Camera::updateLookDirectionCallback() 
{
	lookDirection = pointToLookAt - pos;
	normalize(lookDirection);
	lookDirectionFlat = lookDirection;
	lookDirectionFlat.y = 0;
	normalize(lookDirectionFlat);
}

void Camera::updateSideDirectionCallback() 
{
	sideDirection = sf::Vector3f(-lookDirection.z, 0, lookDirection.x); //sneaky method all adjacent vectors on plane be like [(a,b), (-b,a)]
	normalize(sideDirection);
}

void Camera::updatePointToLookAtPosition(sf::Vector3f newPos) 
{
	pointToLookAt = newPos;

	pointToLookAt.y += 1;
}

void Camera::updateWalkDirection(const InputController &input) 
{
	sf::Vector3f newWalkDir = sf::Vector3f(0, 0, 0);

	if (input.getKeyW())
	{
		 newWalkDir += lookDirectionFlat * input.getKeyW();
	}

	if (input.getKeyS())
	{
		newWalkDir -= lookDirectionFlat * input.getKeyS();
	}

	if (input.getKeyA())
	{
		newWalkDir -= sideDirection * input.getKeyA();
	}

	if (input.getKeyD())
	{
		newWalkDir += sideDirection * input.getKeyD();
	}
	if(vec3Length(newWalkDir.x, newWalkDir.y, newWalkDir.z) > 1)
	{
		normalize(newWalkDir);
	}
	std::cout << walkDirection.x << "   "<< walkDirection.y<< "    " << walkDirection.z<<std::endl;
	walkDirection = newWalkDir;
}

glm::mat4 Camera::moveCamera() 
{	
	return glm::lookAt(glm::vec3(pos.x, pos.y, pos.z), glm::vec3(pointToLookAt.x, pointToLookAt.y, pointToLookAt.z), glm::vec3(0,1,0));
}