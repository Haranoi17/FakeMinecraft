#include <Headers.hpp>
#include <classes.hpp>
#include <functions.hpp>

btDefaultCollisionConfiguration* 	collisionConfiguration;
btDiscreteDynamicsWorld* 			dynamicsWorld;
btRigidBody* 						groundRigidBody;
btTransform 						trans;
Camera* 							cam = new Camera();
World								generatedWorld(1);
Player* 							player = new Player();
std::vector<btRigidBody*> 			bullets;
std::vector<Enemy*> 				enemies;
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
GLUquadric*							quad;
GLuint 								program;
static const char* 					vertexShaderPath = "/home/haranoi17/Documents/Projects/OpenGl_SFML/shaders/vertexShader.vert";
static const char* 					fragmentShaderPath = "/home/haranoi17/Documents/Projects/OpenGl_SFML/shaders/fragmentShader.frag";

void initValues()
{
	crosshairTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/crosshair.png");
	dirtTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/dirt.jpg");
	grassTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/grass.jpg");
	grassTopTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/grassTop.png");
	program = initShaders(vertexShaderPath, fragmentShaderPath);
	window.setMouseCursorVisible(false);
}

int main(int argc, char** argv)
{
	window.create(sf::VideoMode(1920, 1080), "SfmlOpenGl", sf::Style::Fullscreen, sf::ContextSettings(24, 8, 2));
	glutInit(&argc, argv);
	glewInit();
	initBullet();
	initGL();
	initValues();

	reshapeScreen();

	while (window.isOpen())
	{
		eventHandling();
		update();
		dealWithCollisions();

		drawScreen();
		window.display();
	}

	finishBullet();
	return 0;
}