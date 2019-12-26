#include <initValues.hpp>
#include <externs.hpp>
#include <functions.hpp>
#include <filesystem>

void initValues()
{
	crosshairTexture.loadFromFile(std::filesystem::current_path() += "/../textures/crosshair.png");
	dirtTexture.loadFromFile(std::filesystem::current_path() += "/../textures/dirt.jpg");
	grassTexture.loadFromFile(std::filesystem::current_path() += "/../textures/grass.jpg");
	grassTopTexture.loadFromFile(std::filesystem::current_path() += "/../textures/grassTop.png");
	skyboxTexture.loadFromFile(std::filesystem::current_path() += "/../textures/skybox.jpeg");
	stoneTexture.loadFromFile(std::filesystem::current_path() += "/../textures/stone.png");
    woodTexture.loadFromFile(std::filesystem::current_path() += "/../textures/wood.jpg");
    leavesTexture.loadFromFile(std::filesystem::current_path() += "/../textures/leaves.png");

    blocksShader = Shader(std::filesystem::current_path() += "/../shaders/blocksShader.vert", std::filesystem::current_path() += "/../shaders/blocksShader.frag");
    blocksShader.projectionLoc = glGetUniformLocation(blocksShader.getID(), "projection");
    blocksShader.viewLoc = glGetUniformLocation(blocksShader.getID(), "view");  
    
    blocksShader.use();

    GLuint texLoc = glGetUniformLocation(blocksShader.getID(), "grassTop");
    glUniform1i(texLoc, 0);

    texLoc = glGetUniformLocation(blocksShader.getID(), "grassSide");
    glUniform1i(texLoc, 1);
    
    texLoc = glGetUniformLocation(blocksShader.getID(), "dirt");
    glUniform1i(texLoc, 2);

    texLoc = glGetUniformLocation(blocksShader.getID(), "stone");
    glUniform1i(texLoc, 3);

    texLoc = glGetUniformLocation(blocksShader.getID(), "wood");
    glUniform1i(texLoc, 4);

    texLoc = glGetUniformLocation(blocksShader.getID(), "leaves");
    glUniform1i(texLoc, 5);

    glUseProgram(0);
	
	playerShader = Shader(std::filesystem::current_path() += "/../shaders/playerShader.vert", std::filesystem::current_path() += "/../shaders/playerShader.frag");
	playerShader.viewLoc = glGetUniformLocation(playerShader.getID(), "view");
    playerShader.modelLoc = glGetUniformLocation(playerShader.getID(), "model");
    playerShader.projectionLoc = glGetUniformLocation(playerShader.getID(), "projection");
    playerShader.use();
    texLoc = glGetUniformLocation(playerShader.getID(), "tex0");
    glUniform1i(texLoc, 15);

    glUseProgram(0);
    
	window.setMouseCursorVisible(false);

}