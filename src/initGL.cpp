#include <externs.hpp>
#include <initGL.hpp>

void initGL()
{

	const GLubyte* version = glGetString(GL_VERSION);
	std::cout << version << std::endl;
	int i;
	glGetIntegerv(GL_MINOR_VERSION, &i);
	std::cout << i << std::endl;

		glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glLineWidth(3);
	glBlendEquation(GL_ONE_MINUS_SRC_ALPHA);
	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
	quad = gluNewQuadric();
}