#include <externs.hpp>
#include <finishBullet.hpp>

void finishBullet()
{
	for (auto &enemy : enemies) dynamicsWorld->removeRigidBody(enemy->enemyRigidBody);
	dynamicsWorld->removeRigidBody(groundRigidBody);

	delete groundRigidBody->getMotionState();
	delete groundRigidBody;
	delete dynamicsWorld;
	delete collisionConfiguration;
}
