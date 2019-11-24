#include <externs.hpp>
#include <initBullet.hpp>

void initBullet()
{
	collisionConfiguration = 	new btDefaultCollisionConfiguration();
	dynamicsWorld = 			new btDiscreteDynamicsWorld(new btCollisionDispatcher(collisionConfiguration), new btDbvtBroadphase(), new btSequentialImpulseConstraintSolver, collisionConfiguration);
	groundRigidBody = 			new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(0, new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0))), new btStaticPlaneShape(btVector3(0, 1, 0), 1), btVector3(0, 0, 0)));
	btScalar 					mass = 1;
	btVector3 					fallInertia(1, 1, 1);
	
	for (int i = 0; i < generatedWorld.positions.size(); i++)
	{
		blocks.push_back(new Enemy());
	}

	groundRigidBody->setRestitution(1.0);
	groundRigidBody->setFriction(0);
	dynamicsWorld->setGravity(btVector3(0, -10, 0));
	dynamicsWorld->addRigidBody(groundRigidBody);
	dynamicsWorld->addRigidBody(player->playerRigidBody);
	


	int i = 0;
	for (auto &block : blocks)
	{
		block->RigidBody->setRestitution(0.5);
		block->RigidBody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT | btCollisionObject::CF_STATIC_OBJECT);
		trans = block->RigidBody->getWorldTransform();
		trans.getOrigin() = generatedWorld.positions[i];
		if(i < blocks.size())
		{
			i++;
		}
		block->RigidBody->setWorldTransform(trans);
		block->RigidBody->getMotionState()->setWorldTransform(trans); 
		dynamicsWorld->addRigidBody(block->RigidBody);
	}


}
