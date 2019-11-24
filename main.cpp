#include <Headers.hpp>
#include <classes.hpp>
#include <functions.hpp>

#include <glm/matrix.hpp>
#include <shader.h>
#include <glew.h>

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

GLuint VAO;
GLuint VBO;

float unitMatrix[16] = 
{
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1
};
static float cubeData[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};
glm::mat4 view = glm::mat4(1);
glm::mat4 projection = glm::mat4(1);
glm::mat4 model = glm::mat4(1);



void initVO()
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData), cubeData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);
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
    Shader shaderKurwa("/home/haranoi17/Documents/Projects/OpenGl_SFML/vertexShader.vert","/home/haranoi17/Documents/Projects/OpenGl_SFML/fragmentShader.frag");
	while (window.isOpen())
	{
		eventHandling();
		update();
		dealWithCollisions();

		drawScreen(shaderKurwa);
		window.display();
	}
	finishBullet();
	return 0;
}