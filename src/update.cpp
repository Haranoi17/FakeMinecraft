#include <externs.hpp>
#include <functions.hpp> //update.hpp is already here
#include <math.h>

void updateLightPos()
{
	lightPos[0] = player->trans.getOrigin().getX() + 1;
	lightPos[1] = player->trans.getOrigin().getY() + 1;
	lightPos[2] = player->trans.getOrigin().getZ();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void updateGunPosition()
{
	// gunPosition = cam.pointToLookAt + sf::Vector3f();
	// gunPosition.x += cos(cam.rot.x/6.28 - 1.57);
	// gunPosition.z += sin((float)cam.rot.x/6.28 - 1.57); 
	static float pi	= (float)3.14159265359;
	float alpha = cam.rot.x / (2 * pi);
	float beta	= -cam.rot.y / (2 * pi);
	gunPosition = cam.pointToLookAt;
	gunPosition.x += 3* -cos(alpha)*cos(beta);
	gunPosition.y += 3*-sin(beta);
	gunPosition.z += 3*-cos(beta)*sin(alpha);
}

void updateCrosshairPosition()
{
	crosshairPos = cam.pointToLookAt;
	crosshairPos.x -= 0.5;
	crosshairPos.y -= 2;
}

void update()
{
	input.updateMouseAndKeyValues();
	cam.updateCameraRotation(input, mouseSpeed);
	
	cam.updateWalkDirection(input);
	player->walk(input, cam);
	

	// dynamicsWorld->stepSimulation(worldTimer.getElapsedTime().asSeconds());

	// worldTimer.restart();

	cam.updatePointToLookAtPosition(sf::Vector3f((float)player->trans.getOrigin().getX(), (float)(player->trans.getOrigin().getY() + 0.5), (float)player->trans.getOrigin().getZ()));
	cam.updateCameraPosition();

	//updateLightPos();
	updateGunPosition();
	updateCrosshairPosition();

	
}

