#pragma once

#include <Headers.hpp>
#include <classes.hpp>

extern btDefaultCollisionConfiguration* 	collisionConfiguration;
extern btDiscreteDynamicsWorld* 			dynamicsWorld;
extern btRigidBody* 						groundRigidBody;
extern btTransform 						    trans;
extern Camera* 							    cam;
extern Player* 							    player;
extern std::vector<btRigidBody*> 			bullets;
extern std::vector<Enemy*> 				    enemies;
extern sf::RenderWindow 					window;
extern sf::Clock 							worldTimer;
extern sf::Clock							animationTimer;
extern sf::Event 							event;
extern sf::Vector3f                         gunPosition;
extern float 								lightPos[4];
extern float 								ambientLight[4];
extern float 								fov;
extern float								mouseSpeed;
extern float                                x;
extern GLUquadric*							quad;
extern GLuint                               program;
