#include <Headers.hpp>
#include <classes.hpp>
#include <functions.hpp>

btDefaultCollisionConfiguration* 	collisionConfiguration;
btDiscreteDynamicsWorld* 			dynamicsWorld;
btRigidBody* 						groundRigidBody;
btTransform 						trans;
Camera* 							cam = new Camera();
World								generatedWorld(1, 50, 50);
Player* 							player = new Player();
std::vector<btRigidBody*> 			bullets;
std::vector<Enemy*> 				blocks;
std::vector<Enemy*>					blocksBuffor;
sf::RenderWindow 					window(sf::VideoMode(800, 600), "SfmlOpenGl", 7U, sf::ContextSettings(24, 8, 2));
sf::Vector3f						gunPosition;
sf::Vector3f 						crosshairPos;
sf::Clock 							worldTimer = sf::Clock();
sf::Clock							animationTimer = sf::Clock();
sf::Event 							event;
sf::Texture 						crosshairTexture;
sf::Texture							dirtTexture;
sf::Texture							grassTexture;
sf::Texture							grassTopTexture;
float 								lightPos[] = { 0, 3, 0, 1 };
float 								ambientLight[] = {0.2,0.2,0.2,1};
float 								fov = 60;
float 								x = 0;
float								mouseSpeed = 0.05;
float								drawDistance = 10;
GLUquadric*							quad;

sf::Clock blocksTimer;

void segregateBlocks()
{
	btTransform 						test;
	//player->trans = player->RigidBody->getWorldTransform();
	for (auto &block : blocks)
	{
		block->RigidBody->getMotionState()->getWorldTransform(test);
		btVector3 dist = btVector3(test.getOrigin().getX() - player->trans.getOrigin().getX(), test.getOrigin().getY() - player->trans.getOrigin().getY(), test.getOrigin().getZ() - player->trans.getOrigin().getZ());

		
		if(dist.length2() > drawDistance * drawDistance)
		{
			blocksBuffor.push_back(block);
			blocks.erase(std::remove(blocks.begin(), blocks.end(), block), blocks.end());
		}
	}

	for (auto &block : blocksBuffor)
	{
		block->RigidBody->getMotionState()->getWorldTransform(test);
		btVector3 dist = btVector3(test.getOrigin().getX() - player->trans.getOrigin().getX(), test.getOrigin().getY() - player->trans.getOrigin().getY(), test.getOrigin().getZ() - player->trans.getOrigin().getZ());

		
		if(dist.length2() < drawDistance * drawDistance)
		{
			blocks.push_back(block);
			blocksBuffor.erase(std::remove(blocksBuffor.begin(), blocksBuffor.end(), block), blocksBuffor.end());
		}
	}
}
void updateLightPos()
{
	player->RigidBody->getMotionState()->getWorldTransform(trans);

	lightPos[0] = trans.getOrigin().getX() + 1;
	lightPos[1] = trans.getOrigin().getY() + 1;
	lightPos[2] = trans.getOrigin().getZ();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

int main(int argc, char** argv)
{
	
	//window.create(sf::VideoMode(1920, 1080), "SfmlOpenGl", sf::Style::Fullscreen, sf::ContextSettings(24, 8, 2));
	glutInit(&argc, argv);
	glewInit();
	initBullet();
	initGL();
	initValues();
	reshapeScreen();

	segregateBlocks();
	sf::Thread t1(segregateBlocks);
	while (window.isOpen())
	{
		eventHandling();
		update();
		t1.launch();
		updateLightPos();

			
		drawScreen();
		window.display();
	}
	finishBullet();
	return 0;
}