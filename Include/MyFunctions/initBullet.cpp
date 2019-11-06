#include <externs.hpp>
#include <initBullet.hpp>

void initBullet()
{
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dynamicsWorld = new btDiscreteDynamicsWorld(new btCollisionDispatcher(collisionConfiguration), new btDbvtBroadphase(), new btSequentialImpulseConstraintSolver, collisionConfiguration);
	groundRigidBody = new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(0, new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0))), new btStaticPlaneShape(btVector3(0, 1, 0), 1), btVector3(0, 0, 0)));

	btScalar mass = 1;
	btVector3 fallInertia(1, 1, 1);
	for (unsigned char i = 0; i < 10; i++)
	{
		enemies.push_back(new Enemy());
	}

	dynamicsWorld->setGravity(btVector3(0, -10, 0));
	groundRigidBody->setRestitution(1.0);
	groundRigidBody->setFriction(0);
	dynamicsWorld->addRigidBody(groundRigidBody);
	dynamicsWorld->addRigidBody(player->playerRigidBody);
	
	for (auto &enemy : enemies)
	{
		enemy->enemyRigidBody->setRestitution(0.5);
		dynamicsWorld->addRigidBody(enemy->enemyRigidBody);
	}
}
