#include <externs.hpp>
#include <reshapeScreen.hpp>

void reshapeScreen()
{
	glViewport(0, 0, window.getSize().x, window.getSize().y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (float)window.getSize().x / (float)window.getSize().y, 0.2, 5000.0);
	glMatrixMode(GL_MODELVIEW);
}
