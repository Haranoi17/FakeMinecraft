#include <Headers.hpp>
#include <classes.hpp>

extern btDefaultCollisionConfiguration* 	collisionConfiguration;
extern btDiscreteDynamicsWorld* 			dynamicsWorld;
extern btRigidBody* 						groundRigidBody;
extern std::vector<btRigidBody*> 			bullets;
extern btTransform 						    trans;
extern sf::RenderWindow 					window;
extern Camera* 							    cam;
extern Player* 							    player;
extern std::vector<Enemy*> 				    enemies;
extern sf::Clock 							worldTimer;
extern sf::Clock							animationTimer;
extern sf::Event 							event;
extern float 								lightPos[4];
extern float 								ambientLight[4];
extern float 								fov;
extern float								mouseSpeed;
extern GLUquadric*							quad;
extern GLuint                               program;
extern float                                x;
