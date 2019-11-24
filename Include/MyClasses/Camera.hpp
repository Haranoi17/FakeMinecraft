#pragma once

#include <Bullet/btBulletDynamicsCommon.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <GL/freeglut.h>
#include <glm/matrix.hpp>
#include <iostream>
#include <math.h>

///Camera class represents necessary data to move in 3D space.
///
///It inherits from Collidable class
///### Example
///~~~.cpp
/// Camera* a = new Camera(); // a comment
///~~~
class Camera
{
public:
	Camera();
	~Camera();
	///Represents position in 3D space and it's used in updateCameraPosition() to update it's values.
	sf::Vector3f pos;
	///Gathers some information about mose move and then it's values are used in updateCameraRotation(float, float).
	sf::Vector2f rot;
	///Imaginary point to look at by camera it uses **rot** vector to update it's sferical position around camera.
	sf::Vector3f pointToLookAt;
	///it's just **pointToLookAt** - **pos** vector wich is used to determin the **walkDirection** vector but it depends on the logic. 
	sf::Vector3f lookDirection;
	sf::Vector3f lookDirectionFlat;
	///Vector that determines towards which direction the camera should move.
	sf::Vector3f walkDirection;
	///It's vector in xz plane (the floor) adjacent to (**pos.x**, 0,**pos.z**) and it is just (-**pos.z**, 0, **pos.x**).
	sf::Vector3f sideDirection;

	void updateCameraPosition();
	void updateCameraRotation(sf::Vector2i d, float mouseSpeed);
	
	void updateWalkDirection();

	void updatePointToLookAtPosition(sf::Vector3f newPos);
	//These are used in position and rotation update funcs
	void updateLookDirectionCallback();
	void updateSideDirectionCallback();
	//
	glm::mat4 moveCamera();
};

