#include <externs.hpp>
#include <reshapeScreen.hpp>


void reshapeScreen()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, window.getSize().x, window.getSize().y);
	gluPerspective(fov, (float)window.getSize().x / window.getSize().y, 0.2f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
}
