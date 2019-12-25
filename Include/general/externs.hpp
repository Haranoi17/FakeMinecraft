#pragma once

#include <Headers.hpp>
#include <classes.hpp>


extern InputController                      input;
extern Player 							    player;
extern World								generatedWorld;
extern std::vector<Enemy*> 				    blocks;
extern sf::RenderWindow 					window;
extern sf::Clock 							worldTimer;
extern sf::Clock							animationTimer;
extern sf::Event 							event;
extern sf::Vector3f 						crosshairPos;
extern sf::Texture 						    crosshairTexture;
extern sf::Texture							dirtTexture;
extern sf::Texture							grassTexture;
extern sf::Texture							grassTopTexture;
extern sf::Texture                          skyboxTexture;
extern float 								lightPos[4];
extern float 								ambientLight[4];
extern float 								fov;
extern float								mouseSpeed;
extern float                                x;
extern float                                drawDistance;

extern Shader playerShader;
extern Shader blocksShader;

extern GLuint VAO;
extern GLuint VBO[2];
extern float unitMatrix[16];
extern float cubeData[288];

extern glm::mat4 view;
extern glm::mat4 projection;
extern glm::mat4 model;
extern glm::mat4 *matrices;
extern bool matricesReady;