#include "Game.hpp"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>


#include <X11/Xlib.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    XInitThreads();

    Game game;
    game.startLogic();
    game.drawLoop();
}