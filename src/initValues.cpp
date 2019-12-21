#include <initValues.hpp>
#include <externs.hpp>
#include <functions.hpp>


void initValues()
{
	crosshairTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/crosshair.png");
	dirtTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/dirt.jpg");
	grassTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/grass.jpg");
	grassTopTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/grassTop.png");
	
	
    blocksShader = Shader("/home/haranoi17/Documents/Projects/OpenGl_SFML/shaders/blocksShader.vert", "/home/haranoi17/Documents/Projects/OpenGl_SFML/shaders/blocksShader.frag");
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
	
	playerShader = Shader("/home/haranoi17/Documents/Projects/OpenGl_SFML/shaders/playerShader.vert", "/home/haranoi17/Documents/Projects/OpenGl_SFML/shaders/playerShader.frag");
	playerShader.viewLoc = glGetUniformLocation(playerShader.getID(), "view");
    playerShader.modelLoc = glGetUniformLocation(playerShader.getID(), "model");
    playerShader.projectionLoc = glGetUniformLocation(playerShader.getID(), "projection");
	window.setMouseCursorVisible(false);

}