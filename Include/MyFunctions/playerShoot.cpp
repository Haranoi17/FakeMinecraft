#include <externs.hpp>
#include <playerShoot.hpp>

void playerShoot()
{
	static bool 		blockLeft = false;
	static sf::Clock 	timer = sf::Clock();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !blockLeft)
	{
		bullets.push_back(new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(btScalar(0.2), new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1),
							btVector3((btScalar)gunPosition.x, (btScalar)(gunPosition.y), (btScalar)gunPosition.z))), new btSphereShape((btScalar)0.2), btVector3(1, 1, 1))));

		bullets.back()->applyCentralImpulse(btVector3(cam->lookDirection.x * 10, cam->lookDirection.y * 10, cam->lookDirection.z * 10));
		dynamicsWorld->addRigidBody(bullets.back());
		blockLeft = true;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && blockLeft)
	{
		blockLeft = true;
	}
	else
	{
		blockLeft = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && bullets.size())

	{
		dynamicsWorld->removeRigidBody(bullets.back());
		bullets.pop_back();
	}
	timer.restart();
}
