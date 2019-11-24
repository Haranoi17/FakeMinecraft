#include <externs.hpp>
#include <finishBullet.hpp>

void finishBullet()
{
	for (auto &block : blocks) dynamicsWorld->removeRigidBody(block->RigidBody);
	
	dynamicsWorld->removeRigidBody(groundRigidBody);

	delete groundRigidBody->getMotionState();
	delete groundRigidBody;
	delete dynamicsWorld;
	delete collisionConfiguration;
}
