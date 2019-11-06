#include <externs.hpp>
#include <functions.hpp> //update.hpp is already here


void updateLightPos()
{
	player->playerRigidBody->getMotionState()->getWorldTransform(trans);

	lightPos[0] = trans.getOrigin().getX() + 1;
	lightPos[1] = trans.getOrigin().getY() + 1;
	lightPos[2] = trans.getOrigin().getZ();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}


void update()
{
	cam->updateCameraRotation(mouseHandling(), mouseSpeed);
	
	cam->updateWalkDirection();
	player->walk(btVector3(cam->walkDirection.x, cam->walkDirection.y, cam->walkDirection.z));
	playerShoot();

	dynamicsWorld->stepSimulation(worldTimer.getElapsedTime().asSeconds());
	worldTimer.restart();

	player->playerRigidBody->getMotionState()->getWorldTransform(trans);
	cam->updatePointToLookAtPosition(sf::Vector3f((float)trans.getOrigin().getX(), (float)(trans.getOrigin().getY() + 0.5), (float)trans.getOrigin().getZ()));
	cam->updateCameraPosition();

	updateLightPos();
}

