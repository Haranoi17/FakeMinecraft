#include <Headers.hpp>
#include <classes.hpp>
#include <functions.hpp>

btDefaultCollisionConfiguration* 	collisionConfiguration;
btDiscreteDynamicsWorld* 			dynamicsWorld;
btRigidBody* 						groundRigidBody;
btTransform 						trans;
btTransform							playerTrans;
Camera* 							cam = new Camera();
World								generatedWorld(1);
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
float								drawDistance = 20;
GLUquadric*							quad;

sf::Clock blocksTimer;

void segregateBlocks()
{
	std::cout << "dupa";
	for (auto &block : blocks)
	{
		block->RigidBody->getMotionState()->getWorldTransform(trans);
		btVector3 dist = btVector3(trans.getOrigin().getX() - playerTrans.getOrigin().getX(), trans.getOrigin().getY() - playerTrans.getOrigin().getY(), trans.getOrigin().getZ() - playerTrans.getOrigin().getZ());

		
		if(dist.length2() > drawDistance * drawDistance)
		{
			blocksBuffor.push_back(block);
			blocks.erase(std::remove(blocks.begin(), blocks.end(), block), blocks.end());
		}
	}

	for (auto &block : blocksBuffor)
	{
		block->RigidBody->getMotionState()->getWorldTransform(trans);
		btVector3 dist = btVector3(trans.getOrigin().getX() - playerTrans.getOrigin().getX(), trans.getOrigin().getY() - playerTrans.getOrigin().getY(), trans.getOrigin().getZ() - playerTrans.getOrigin().getZ());

		
		if(dist.length2() < drawDistance * drawDistance)
		{
			blocks.push_back(block);
			blocksBuffor.erase(std::remove(blocksBuffor.begin(), blocksBuffor.end(), block), blocksBuffor.end());
		}
	}
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

	while (window.isOpen())
	{
		eventHandling();
		update();
		dealWithCollisions();

		if(blocksTimer.getElapsedTime().asSeconds() > 5)
		{
			segregateBlocks();
			blocksTimer.restart();
		}
		drawScreen();
		window.display();
	}
	finishBullet();
	return 0;
}