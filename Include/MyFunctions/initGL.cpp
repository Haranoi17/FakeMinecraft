#include <externs.hpp>
#include <initGL.hpp>

void initGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glLineWidth(3);

	quad = gluNewQuadric();
}