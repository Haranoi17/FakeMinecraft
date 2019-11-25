#include <externs.hpp>
#include <functions.hpp> //update.hpp is already here
#include <math.h>



void updateGunPosition()
{
	gunPosition = cam->pointToLookAt;
	gunPosition.x += cos(cam->rot.x/6.28 - 1.57);
	gunPosition.z += sin((float)cam->rot.x/6.28 - 1.57); 
	//TODO: zrobic tak zeby sie obracal z kamerka
}

void updateCrosshairPosition()
{
	crosshairPos = cam->pointToLookAt;
	crosshairPos.x -= 0.5;
	crosshairPos.y -= 2;
}

void update()
{
	cam->updateCameraRotation(mouseHandling(), mouseSpeed);
	
	cam->updateWalkDirection();
	player->walk(btVector3(cam->walkDirection.x, cam->walkDirection.y, cam->walkDirection.z));
	playerShoot();

	dynamicsWorld->stepSimulation(worldTimer.getElapsedTime().asSeconds(),3);
	worldTimer.restart();

	player->RigidBody->getMotionState()->getWorldTransform(player->trans);
	cam->updatePointToLookAtPosition(sf::Vector3f((float)player->trans.getOrigin().getX(), (float)(player->trans.getOrigin().getY() + 0.5), (float)player->trans.getOrigin().getZ()));
	cam->updateCameraPosition();

	// updateLightPos();
	updateGunPosition();
	updateCrosshairPosition();
	dealWithCollisions();

	glLoadIdentity();
	cam->moveCamera();
}

