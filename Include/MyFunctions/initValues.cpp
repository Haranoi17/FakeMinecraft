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
	
	
    blocksShader = Shader(std::filesystem::current_path() += "/../shaders/blocksShader.vert", std::filesystem::current_path() += "/../shaders/blocksShader.frag");
    blocksShader.projectionLoc = glGetUniformLocation(blocksShader.getID(), "projection");
    blocksShader.viewLoc = glGetUniformLocation(blocksShader.getID(), "view");  
    
    blocksShader.use();

    GLuint texLoc = glGetUniformLocation(blocksShader.getID(), "tex0");
    glUniform1i(texLoc, 0);

    texLoc = glGetUniformLocation(blocksShader.getID(), "tex1");
    glUniform1i(texLoc, 1);
    
    texLoc = glGetUniformLocation(blocksShader.getID(), "tex2");
    glUniform1i(texLoc, 2);

    glUseProgram(0);
	
	playerShader = Shader(std::filesystem::current_path() += "/../shaders/playerShader.vert", std::filesystem::current_path() += "/../shaders/playerShader.frag");
	playerShader.viewLoc = glGetUniformLocation(playerShader.getID(), "view");
    playerShader.modelLoc = glGetUniformLocation(playerShader.getID(), "model");
    playerShader.projectionLoc = glGetUniformLocation(playerShader.getID(), "projection");
	window.setMouseCursorVisible(false);

}