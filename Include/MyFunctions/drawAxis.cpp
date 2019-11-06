#include <SFML/OpenGL.hpp>
#include <drawAxis.hpp>

void drawAxis()
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1000, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1000);

	glEnd();


	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(-1000, 0, 0);
	glVertex3f(0, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, -1000, 0);
	glVertex3f(0, 0, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -1000);
	glVertex3f(0, 0, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

}