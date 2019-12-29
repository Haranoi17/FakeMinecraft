#include <Headers.hpp>
#include <functions.hpp>
#include <classes.hpp>
#include <glm/matrix.hpp>
#include <glew.h>

InputController                     input = InputController();
World								generatedWorld(1);
Player 							    player = Player(generatedWorld);
sf::RenderWindow 					window(sf::VideoMode(800, 600), "SfmlOpenGl", 7U, sf::ContextSettings(24, 8, 2));
sf::Vector3f 						crosshairPos;
sf::Clock 							worldTimer = sf::Clock();
sf::Clock							animationTimer = sf::Clock();
sf::Event 							event;
sf::Texture 						crosshairTexture;
sf::Texture							dirtTexture;
sf::Texture							grassTexture;
sf::Texture							grassTopTexture;
sf::Texture                         skyboxTexture;
sf::Texture                         stoneTexture;
sf::Texture                         woodTexture;
sf::Texture                         leavesTexture;
float 								lightPos[] = { 0, 3, 0, 1 };
float 								ambientLight[] = {0.2,0.2,0.2,1};
float 								fov = 60;
float 								x = 0;
float								mouseSpeed = 0.05;
float								drawDistance = 20;

Shader playerShader;
Shader blocksShader;

GLuint VAO;
GLuint VBO[3];

float unitMatrix[16] = 
{
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1
};
float cubeData[288] = {
    //positions        //texCoords  //normals  
    -0.5f,-0.5f,-0.5f,    0.0f, 1.0f,        0.0f, 0.0f, 1.0f,      
     0.5f,-0.5f,-0.5f,    1.0f, 1.0f,        0.0f, 0.0f, 1.0f,
     0.5f, 0.5f,-0.5f,    1.0f, 0.0f,        0.0f, 0.0f, 1.0f,
    -0.5f,-0.5f,-0.5f,    0.0f, 1.0f,        0.0f, 0.0f, 1.0f,
     0.5f, 0.5f,-0.5f,    1.0f, 0.0f,        0.0f, 0.0f, 1.0f,
    -0.5f, 0.5f,-0.5f,    0.0f, 0.0f,        0.0f, 0.0f, 1.0f,
     0.5f,-0.5f, 0.5f,    0.0f, 1.0f,        0.0f, 0.0f,-1.0f,
    -0.5f,-0.5f, 0.5f,    1.0f, 1.0f,        0.0f, 0.0f,-1.0f,
    -0.5f, 0.5f, 0.5f,    1.0f, 0.0f,        0.0f, 0.0f,-1.0f,
     0.5f,-0.5f, 0.5f,    0.0f, 1.0f,        0.0f, 0.0f,-1.0f,
    -0.5f, 0.5f, 0.5f,    1.0f, 0.0f,        0.0f, 0.0f,-1.0f,
     0.5f, 0.5f, 0.5f,    0.0f, 0.0f,        0.0f, 0.0f,-1.0f,
    -0.5f,-0.5f, 0.5f,    0.0f, 1.0f,        0.0f,-1.0f, 0.0f,
     0.5f,-0.5f, 0.5f,    1.0f, 1.0f,        0.0f,-1.0f, 0.0f,
     0.5f,-0.5f,-0.5f,    1.0f, 0.0f,        0.0f,-1.0f, 0.0f,
    -0.5f,-0.5f, 0.5f,    0.0f, 1.0f,        0.0f,-1.0f, 0.0f,
     0.5f,-0.5f,-0.5f,    1.0f, 0.0f,        0.0f,-1.0f, 0.0f,
    -0.5f,-0.5f,-0.5f,    0.0f, 0.0f,        0.0f,-1.0f, 0.0f,
    -0.5f, 0.5f,-0.5f,    0.0f, 1.0f,        0.0f, 1.0f, 0.0f,
     0.5f, 0.5f,-0.5f,    1.0f, 1.0f,        0.0f, 1.0f, 0.0f,
     0.5f, 0.5f, 0.5f,    1.0f, 0.0f,        0.0f, 1.0f, 0.0f,
    -0.5f, 0.5f,-0.5f,    0.0f, 1.0f,        0.0f, 1.0f, 0.0f,
     0.5f, 0.5f, 0.5f,    1.0f, 0.0f,        0.0f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f,    0.0f, 0.0f,        0.0f, 1.0f, 0.0f,
    -0.5f,-0.5f, 0.5f,    0.0f, 1.0f,       -1.0f, 0.0f, 0.0f,
    -0.5f,-0.5f,-0.5f,    1.0f, 1.0f,       -1.0f, 0.0f, 0.0f,
    -0.5f, 0.5f,-0.5f,    1.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
    -0.5f,-0.5f, 0.5f,    0.0f, 1.0f,       -1.0f, 0.0f, 0.0f,
    -0.5f, 0.5f,-0.5f,    1.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f,    0.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
     0.5f,-0.5f,-0.5f,    0.0f, 1.0f,        1.0f, 0.0f, 0.0f,
     0.5f,-0.5f, 0.5f,    1.0f, 1.0f,        1.0f, 0.0f, 0.0f,
     0.5f, 0.5f, 0.5f,    1.0f, 0.0f,        1.0f, 0.0f, 0.0f,
     0.5f,-0.5f,-0.5f,    0.0f, 1.0f,        1.0f, 0.0f, 0.0f,
     0.5f, 0.5f, 0.5f,    1.0f, 0.0f,        1.0f, 0.0f, 0.0f,
     0.5f, 0.5f,-0.5f,    0.0f, 0.0f,        1.0f, 0.0f, 0.0f
};

glm::mat4 view = glm::mat4(1);
glm::mat4 projection = glm::mat4(1);
glm::mat4 model = glm::mat4(1);
glm::mat4 *matrices;
float *blockTypes;
bool matricesReady = false;
bool preparingMatrices = false;
sf::Thread matricePreparationThread = sf::Thread(prepareMatrices);
sf::Clock updateClock = sf::Clock();


bool fpsCtr()
{
    static sf::Clock fpsTimer = sf::Clock();
    static int i;
    i++;
    if(fpsTimer.getElapsedTime().asSeconds() >= 1)
    {
        std::cout << i << " klatek w " << fpsTimer.getElapsedTime().asSeconds() << "s to: " << (float)i/fpsTimer.getElapsedTime().asSeconds() << "FPS" << std::endl;
        if((float)i/fpsTimer.getElapsedTime().asSeconds() < 2)
        {
            std::cout << "Low FPS probably errors" << std::endl;
            //return true;
        }
        i = 0;
        fpsTimer.restart();
    }
    return false;
}



int main(int argc, char** argv)
{
	//window.create(sf::VideoMode(1920, 1080), "SfmlOpenGl", sf::Style::Fullscreen, sf::ContextSettings(24, 8, 2));
	glutInit(&argc, argv);
	glewInit();
	initValues();
	initGL();
    initVO();
	reshapeScreen();

    sf::Clock reRenderTimer = sf::Clock();
    sf::Vector3f renderPoint = player.pos;

	while(window.isOpen())
	{
		eventHandling();
        update();
        placingAndRemovingBlocks();

        if(!input.getMouseLeft() && !input.getMouseRight() && !matricesReady && reRenderTimer.getElapsedTime().asSeconds() > 0.3)
        {
            matricePreparationThread.launch();
            reRenderTimer.restart();
        }

        if(matricesReady)
        {
            reRenderWorld();  
        }
    
        drawScreen();
		window.display();
        if(fpsCtr())
        {
            window.close();
        }
	}

	return 0;
}