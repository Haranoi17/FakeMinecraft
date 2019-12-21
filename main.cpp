#include <Headers.hpp>
#include <classes.hpp>
#include <functions.hpp>

#include <glm/matrix.hpp>
#include <glew.h>

InputController                     input = InputController();
btDefaultCollisionConfiguration* 	collisionConfiguration;
btDiscreteDynamicsWorld* 			dynamicsWorld;
btRigidBody* 						groundRigidBody;
btTransform 						trans;
Camera 							    cam = Camera(); 
World								generatedWorld(1);
Player* 							player = new Player();
std::vector<btRigidBody*> 			bullets;
std::vector<Enemy*> 				    blocks;
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

Shader playerShader;
Shader blocksShader;

GLuint VAO;
GLuint VBO[2];

float unitMatrix[16] = 
{
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1
};
static float cubeData[] = {
    //positions        //texCoords  //normals  
    -1.0f,-1.0f, 1.0f,     0.0f, 1.0f,        0.0f, 0.0f, 1.0f,
     1.0f,-1.0f, 1.0f,     1.0f, 1.0f,        0.0f, 0.0f, 1.0f,
     1.0f, 1.0f, 1.0f,     1.0f, 0.0f,        0.0f, 0.0f, 1.0f,  
    -1.0f,-1.0f, 1.0f,     0.0f, 1.0f,        0.0f, 0.0f, 1.0f,
     1.0f, 1.0f, 1.0f,     1.0f, 0.0f,        0.0f, 0.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,     0.0f, 0.0f,        0.0f, 0.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,     0.0f, 1.0f,        0.0f, 0.0f,-1.0f,
     1.0f,-1.0f,-1.0f,     1.0f, 1.0f,        0.0f, 0.0f,-1.0f,
     1.0f, 1.0f,-1.0f,     1.0f, 0.0f,        0.0f, 0.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,     0.0f, 1.0f,        0.0f, 0.0f,-1.0f,
     1.0f, 1.0f,-1.0f,     1.0f, 0.0f,        0.0f, 0.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,     0.0f, 0.0f,        0.0f, 0.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,     0.0f, 1.0f,        0.0f,-1.0f, 0.0f,
     1.0f,-1.0f,-1.0f,     1.0f, 1.0f,        0.0f,-1.0f, 0.0f,
     1.0f,-1.0f, 1.0f,     1.0f, 0.0f,        0.0f,-1.0f, 0.0f,
    -1.0f,-1.0f,-1.0f,     0.0f, 1.0f,        0.0f,-1.0f, 0.0f,
     1.0f,-1.0f, 1.0f,     1.0f, 0.0f,        0.0f,-1.0f, 0.0f,
    -1.0f,-1.0f, 1.0f,     0.0f, 0.0f,        0.0f,-1.0f, 0.0f,
    -1.0f, 1.0f, 1.0f,     0.0f, 1.0f,        0.0f, 1.0f, 0.0f,
     1.0f, 1.0f, 1.0f,     1.0f, 1.0f,        0.0f, 1.0f, 0.0f,
     1.0f, 1.0f,-1.0f,     1.0f, 0.0f,        0.0f, 1.0f, 0.0f,
    -1.0f, 1.0f, 1.0f,     0.0f, 1.0f,        0.0f, 1.0f, 0.0f,
     1.0f, 1.0f,-1.0f,     1.0f, 0.0f,        0.0f, 1.0f, 0.0f,
    -1.0f, 1.0f,-1.0f,     0.0f, 0.0f,        0.0f, 1.0f, 0.0f,  
    -1.0f,-1.0f,-1.0f,     0.0f, 1.0f,       -1.0f, 0.0f, 0.0f,
    -1.0f,-1.0f, 1.0f,     1.0f, 1.0f,       -1.0f, 0.0f, 0.0f,
    -1.0f, 1.0f, 1.0f,     1.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
    -1.0f,-1.0f,-1.0f,     0.0f, 1.0f,       -1.0f, 0.0f, 0.0f,
    -1.0f, 1.0f, 1.0f,     1.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
    -1.0f, 1.0f,-1.0f,     0.0f, 0.0f,       -1.0f, 0.0f, 0.0f,
     1.0f,-1.0f, 1.0f,     0.0f, 1.0f,        1.0f, 0.0f, 0.0f,
     1.0f,-1.0f,-1.0f,     1.0f, 1.0f,        1.0f, 0.0f, 0.0f,
     1.0f, 1.0f,-1.0f,     1.0f, 0.0f,        1.0f, 0.0f, 0.0f,
     1.0f,-1.0f, 1.0f,     0.0f, 1.0f,        1.0f, 0.0f, 0.0f,
     1.0f, 1.0f,-1.0f,     1.0f, 0.0f,        1.0f, 0.0f, 0.0f,
     1.0f, 1.0f, 1.0f,     0.0f, 0.0f,        1.0f, 0.0f, 0.0f,
     
};
glm::mat4 view = glm::mat4(1);
glm::mat4 projection = glm::mat4(1);
glm::mat4 model = glm::mat4(1);



void initVO()
{
	glGenBuffers(2, VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData), cubeData, GL_STREAM_DRAW);

    glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(5 * sizeof(float)));
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);


    glm::mat4 *matrices = new glm::mat4[generatedWorld.ammountToDraw];
    
    int iterator = 0;
    for(auto &block : blocks)
    {
        trans = block->RigidBody->getWorldTransform();
        if(generatedWorld.checkAir(trans.getOrigin()))
        {
            model = glm::translate(glm::mat4(1), glm::vec3(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ()));
            matrices[iterator] = model;
            iterator++;
        }
    }
    
    glBufferData(GL_ARRAY_BUFFER, generatedWorld.ammountToDraw * sizeof(glm::mat4), matrices, GL_STREAM_DRAW);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)0);
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)sizeof(glm::vec4));
    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(2*sizeof(glm::vec4)));
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(3*sizeof(glm::vec4)));

    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);
    glVertexAttribDivisor(6, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    delete[] matrices;
}

void reRenderWorld()
{
    for (int i = 0; i < generatedWorld.ammountToDraw; i++)
	{
		delete blocks[i];
	}

    generatedWorld.prepareToDraw();
 
    blocks.clear();
    for (int i = 0; i < generatedWorld.ammountToDraw; i++)
	{
		blocks.push_back(new Enemy());
	}

    int i = 0;
    for(auto &block : blocks)
    {
        trans = block->RigidBody->getWorldTransform();
        trans.getOrigin() = generatedWorld.blocksToDraw[i].position;
        block->RigidBody->setWorldTransform(trans);
        i++;
    }
    
    glm::mat4 *matrices = new glm::mat4[generatedWorld.ammountToDraw];
    int iterator = 0;
    for(auto &block : blocks)
    {
        trans = block->RigidBody->getWorldTransform();
        if(generatedWorld.checkAir(trans.getOrigin()))
        {
            model = glm::translate(glm::mat4(1), glm::vec3(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ()));
            matrices[iterator] = model;
            iterator++;
        }
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, generatedWorld.ammountToDraw * sizeof(glm::mat4), matrices, GL_STREAM_DRAW);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)0);
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)sizeof(glm::vec4));
    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(2*sizeof(glm::vec4)));
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(3*sizeof(glm::vec4)));

    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);
    glVertexAttribDivisor(6, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    delete[] matrices;
}

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
            return true;
        }
        i = 0;
        fpsTimer.restart();
    }
    return false;
}

void placingAndRemovingBlocks()
{
    if(input.getMouseLeft())
    {
        if(gunPosition.x > 0 && gunPosition.x < generatedWorld.dimentions.getX())
        {
            if(gunPosition.y > 0 && gunPosition.y < generatedWorld.dimentions.getY())
            {
                if(gunPosition.z > 0 && gunPosition.z < generatedWorld.dimentions.getZ())
                {
                    if(generatedWorld.blocks[(int)(gunPosition.x + 0.25)][(int)(gunPosition.y + 0.25)][(int)(gunPosition.z + 0.25)].type != blockType::air)
                    {
                        player->slots.push_back(generatedWorld.blocks[(int)(gunPosition.x + 0.25)][(int)(gunPosition.y + 0.25)][(int)(gunPosition.z + 0.25)].type);
                    }
                    generatedWorld.blocks[(int)(gunPosition.x + 0.25)][(int)(gunPosition.y + 0.25)][(int)(gunPosition.z + 0.25)].type = blockType::air;
                    reRenderWorld();
                }
            }
        }
    }
    if(input.getMouseRight())
    {
        if(gunPosition.x > 0 && gunPosition.x < generatedWorld.dimentions.getX())
        {
            if(gunPosition.y > 0 && gunPosition.y < generatedWorld.dimentions.getY())
            {
                if(gunPosition.z > 0 && gunPosition.z < generatedWorld.dimentions.getZ())
                {
                    
                    if(generatedWorld.blocks[(int)(gunPosition.x + 0.25)][(int)(gunPosition.y + 0.25)][(int)(gunPosition.z + 0.25)].type == blockType::air)
                    {

                        blockType tempType = player->slots.back();
                        if(player->slots.size())
                        {
                            player->slots.pop_back();
                        }
                        generatedWorld.blocks[(int)(gunPosition.x + 0.25)][(int)(gunPosition.y + 0.25)][(int)(gunPosition.z + 0.25)].type = tempType;
                        reRenderWorld();
                    }
                    
                }
            }
        }
    }
}
void freeMemory()
{
    generatedWorld.blocksToDraw.clear();
    
}
int main(int argc, char** argv)
{
	//window.create(sf::VideoMode(1920, 1080), "SfmlOpenGl", sf::Style::Fullscreen, sf::ContextSettings(24, 8, 2));
	glutInit(&argc, argv);
	glewInit();
	initBullet();
	initValues();
	initGL();
    initVO();
	reshapeScreen();

  

	while (window.isOpen())
	{
		eventHandling();
		update();
        //playerShoot();
		//dealWithCollisions();
        placingAndRemovingBlocks();
        std::cout << player->slots.size() << std::endl;
		drawScreen(blocksShader, playerShader);
		window.display();
        if(fpsCtr())
        {
            window.close();
        }
	}
	finishBullet();
    freeMemory();
	return 0;
}