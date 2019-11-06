#include <externs.hpp>
#include <initGL.hpp>

void initGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glLineWidth(3);

	quad = gluNewQuadric();
}