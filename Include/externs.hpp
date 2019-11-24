#pragma once

#include <Headers.hpp>
#include <classes.hpp>
#include <shader.h>

extern btDefaultCollisionConfiguration* 	collisionConfiguration;
extern btDiscreteDynamicsWorld* 			dynamicsWorld;
extern btRigidBody* 						groundRigidBody;
extern btTransform 						    trans;
extern btTransform                          playerTrans;
extern Camera* 							    cam;
extern Player* 							    player;
extern World								generatedWorld;
extern std::vector<btRigidBody*> 			bullets;
extern std::vector<Enemy*> 				    blocks;
extern sf::RenderWindow 					window;
extern sf::Clock 							worldTimer;
extern sf::Clock							animationTimer;
extern sf::Event 							event;
extern sf::Vector3f                         gunPosition;
extern sf::Vector3f 						crosshairPos;
extern sf::Texture 						    crosshairTexture;
extern sf::Texture							dirtTexture;
extern sf::Texture							grassTexture;
extern sf::Texture							grassTopTexture;
extern float 								lightPos[4];
extern float 								ambientLight[4];
extern float 								fov;
extern float								mouseSpeed;
extern float                                x;
extern float                                drawDistance;
extern GLUquadric*							quad;


extern GLuint VAO;
extern GLuint VBO;
extern float unitMatrix[16];

extern glm::mat4 view;
extern glm::mat4 projection;
extern glm::mat4 model;