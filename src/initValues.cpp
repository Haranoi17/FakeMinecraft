#include <initValues.hpp>
#include <externs.hpp>
#include <functions.hpp>


void initValues()
{
	crosshairTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/crosshair.png");
	dirtTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/dirt.jpg");
	grassTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/grass.jpg");
	grassTopTexture.loadFromFile("/home/haranoi17/Documents/Projects/OpenGl_SFML/textures/grassTop.png");
	window.setMouseCursorVisible(false);
}