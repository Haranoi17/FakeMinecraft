#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <array>
#include <vector>
#include "InputController.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "Shader.hpp"
#include "ResourceLoader.hpp"
#include <thread>

class Game
{
    static inline const std::string title{"FakeMinecraft"};
    static inline const sf::Vector2u windowSize{1280, 720};
    static inline const sf::Uint32 windowStyle{7U};
public:
    Game();
    void startLogic();
    void drawLoop();
private:
    void update(float dt);
    void draw();
    void handleEvents();
    void initOpenGL();
    void initValues();
    void initVO();
    void prepareMatrices();
    void reRenderWorld();
    void reshapeScreen();
    void placingAndRemovingBlocks();
    bool checkPlacePossibility(int x, int y, int z);
    bool checkDestroyPossibility(int x, int y, int z);
    sf::Time deltaTime();
    bool isRunning();
    void endGracefully();
    void waitForThreadsToFinnish();
    
private:
    bool isGameRunning{true};
    std::vector<std::thread> m_threads;
    ResourceLoader resourceLoader;
    sf::RenderWindow m_window;

    InputController input;
    World world;
    Player player{world};
    Vector3f crosshairPos;
    Vector3f renderPoint;
    sf::Clock worldTimer;
    sf::Clock animationTimer;
    sf::Texture crosshairTexture;
    sf::Texture dirtTexture;
    sf::Texture grassTexture;
    sf::Texture grassTopTexture;
    sf::Texture skyboxTexture;
    sf::Texture stoneTexture;
    sf::Texture woodTexture;
    sf::Texture leavesTexture;
    std::array<float, 4> lightPos{0, 3, 0, 1};
    std::array<float, 4> ambientLight{0.2, 0.2, 0.2, 1};
    float fov = 60;
    float x = 0;
    float mouseSpeed = 0.05;
    float drawDistance = 20;

    GLuint VAO;
    std::array<GLuint, 3> VBO;

    Shader playerShader;
    Shader blockShader;

    glm::mat4 view{1};
    glm::mat4 projection{1};
    glm::mat4 model{1};
    glm::mat4 *matrices;
    float *blockTypes;
    bool matricesReady = false;
    bool preparingMatrices = false;
    bool preparingBlocks = false;
    bool usingPreparedBlocks = false;
    bool needToRefreshBlocks = false;

    sf::Clock updateClock;
    bool m_updateFinnished{false};
    bool m_eventsFinnished{false};

    float unitMatrix[16] =
        {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1};

    float cubeData[288] = {
        // positions           //texCoords        //normals
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
};