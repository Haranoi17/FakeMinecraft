#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Game.hpp"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    
    Game game;
    game.loop();   
}