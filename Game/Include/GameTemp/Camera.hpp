#pragma once

#include <SFML/Graphics.hpp>
#include <glm/matrix.hpp>
#include <iostream>
#include <InputController.hpp>

class Camera
{
public:
	Camera();
	~Camera();
	
	sf::Vector3f pos;
	sf::Vector2f rot;
	sf::Vector3f pointToLookAt;
	sf::Vector3f lookDirection;
	sf::Vector3f lookDirectionFlat;
	sf::Vector3f walkDirection;
	sf::Vector3f sideDirection;

	void updateCameraPosition();
	void updateCameraRotation(const InputController&, float);
	
	void updateWalkDirection(const InputController&);

	void updatePointToLookAtPosition(sf::Vector3f newPos);
	//These are used in position and rotation update funcs
	void updateLookDirectionCallback();
	void updateSideDirectionCallback();
	//
	glm::mat4 moveCamera();
};

