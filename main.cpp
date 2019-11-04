#include "Headers.hpp"

void initGL();
void initBullet();
void finishBullet();

void reshapeScreen();
void updateFunction();
void updateLightPos();
void eventHandlingFunction();
void mouseWithCamera();
void dealWithCollisions();

void playerShoot();

void drawAxis();
void drawScreen();

btDefaultCollisionConfiguration* 	collisionConfiguration;
btDiscreteDynamicsWorld* 			dynamicsWorld;
btRigidBody* 						groundRigidBody;
std::vector<btRigidBody*> 			bullets;
btTransform 						trans;
sf::RenderWindow 					window(sf::VideoMode(800, 600), "SfmlOpenGl", 7U, sf::ContextSettings(24, 8, 2));
Camera* 							cam = new Camera();
Player* 							player = new Player();
std::vector<Enemy*> 				enemies;
sf::Clock 							worldTimer = sf::Clock();
sf::Event 							event;
float 								lightPos[] = { 0, 3, 0, 1 };
float 								ambientLight[] = {0.2,0.2,0.2,1};
float 								spotDir[] = { 1,0,0 };
float 								fov = 60;
GLUquadric*							quad;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	initBullet();
	initGL();
	reshapeScreen();

	worldTimer.restart();
	dynamicsWorld->computeOverlappingPairs();

	while (window.isOpen())
	{
		eventHandlingFunction();
		updateFunction();
		dealWithCollisions();

		drawScreen();
		window.display();
	}

	finishBullet();
	return 0;
}

void updateLightPos()
{
	player->playerRigidBody->getMotionState()->getWorldTransform(trans);

	lightPos[0] = trans.getOrigin().getX();
	lightPos[1] = trans.getOrigin().getY() + 1;
	lightPos[2] = trans.getOrigin().getZ();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void drawScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor((GLclampf)0.8, (GLclampf)0.8, (GLclampf)0.8, 1);
	glLoadIdentity();

	cam->moveCamera();

	glPushMatrix();
	glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
	gluSphere(quad,0.2,20,20);
	glPopMatrix();
	glColor3f((GLfloat)0.3, (GLfloat)0.2, (GLfloat)0.3);
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();

	for (auto &enemy : enemies)
	{
		glPushMatrix();
		enemy->enemyRigidBody->getMotionState()->getWorldTransform(trans);
		glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
		glColor3f(1, enemy->hp/100.0f, enemy->hp/100.0f);
		glutSolidCube(1);
		glPopMatrix();
	}

	glPushMatrix();
	player->playerRigidBody->getMotionState()->getWorldTransform(trans);
	glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
	//drawCubeColor(1, player->hp / 100.0f, player->hp / 100.0f);
	glColor3f(1, player->hp / 100.0f, player->hp / 100.0f);
	glutSolidCube(1);
	glPopMatrix();  

	for (auto &body : bullets)
	{
		glPushMatrix();
		body->getMotionState()->getWorldTransform(trans);
		glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
		glScalef((GLfloat)0.2, (GLfloat)0.2, (GLfloat)0.2);
		glutSolidCube(1);
		glPopMatrix();
	}

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(3, 4, 0);
	gluSphere(quad,2,40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-3, 4, 0);
	gluCylinder(quad,0,3,4,40,40);
	glPopMatrix();

	drawAxis();
}

void drawAxis()
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1000, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1000);

	glEnd();


	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(-1000, 0, 0);
	glVertex3f(0, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, -1000, 0);
	glVertex3f(0, 0, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -1000);
	glVertex3f(0, 0, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

}

void reshapeScreen()
{
	glViewport(0, 0, window.getSize().x, window.getSize().y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (float)window.getSize().x / (float)window.getSize().y, 0.2, 5000.0);
	glMatrixMode(GL_MODELVIEW);
}

void mouseWithCamera()
{
	static	sf::Vector2f prev = sf::Vector2f((float)window.getSize().x / 2, (float) window.getSize().y / 2);
	sf::Vector2f mousePos = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
	sf::Vector2f d = mousePos - prev;

	cam->updateCameraRotation((float)(d.x * 0.05), (float)(-d.y * 0.05));
	cam->updateCameraPosition();

	if (sf::Mouse::getPosition(window).x <= window.getSize().x / 2 - 200)
	{
		sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, sf::Mouse::getPosition(window).y), window);
		prev.x = (float)window.getSize().x / 2 + 1;
	}
	else if (sf::Mouse::getPosition(window).x >= window.getSize().x / 2 + 200)
	{
		sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, sf::Mouse::getPosition(window).y), window);
		prev.x = (float)window.getSize().x / 2 - 1;
	}

	else if (sf::Mouse::getPosition(window).y <= window.getSize().y / 2 - 200)
	{
		sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(window).x, window.getSize().y / 2), window);
		prev.y = (float)window.getSize().y / 2 + 1;
	}
	else if (sf::Mouse::getPosition(window).y >= window.getSize().y / 2 + 200)
	{
		sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(window).x, window.getSize().y / 2), window);
		prev.y = (float)window.getSize().y / 2 - 1;
	}
	else
	{
		prev.x = (float)sf::Mouse::getPosition(window).x;
		prev.y = (float)sf::Mouse::getPosition(window).y;
	}
}

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

void initGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glLineWidth(3);

	quad = gluNewQuadric();
}

void finishBullet()
{
	for (auto &enemy : enemies) dynamicsWorld->removeRigidBody(enemy->enemyRigidBody);
	dynamicsWorld->removeRigidBody(groundRigidBody);

	delete groundRigidBody->getMotionState();
	delete groundRigidBody;
	delete dynamicsWorld;
	delete collisionConfiguration;
}

void eventHandlingFunction()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::Resized)
		{
			reshapeScreen();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0))
			{
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(window.getSize().x, window.getSize().x, -1.245, -1.245, 0.2, 100);
				glMatrixMode(GL_MODELVIEW);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
			{
				fov += 0.5;
				glViewport(0, 0, (int)window.getSize().x, (int)window.getSize().y);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(fov, (float)window.getSize().x / (float)window.getSize().y, 0.2, 5000.0);
				glMatrixMode(GL_MODELVIEW);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
			{
				fov -= 0.5;
				glViewport(0, 0, window.getSize().x, window.getSize().y);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(fov, (float)window.getSize().x / (float)window.getSize().y, 0.2, 5000.0);
				glMatrixMode(GL_MODELVIEW);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
			{
				reshapeScreen();
			}
		}
	}
}

void updateFunction()
{
	mouseWithCamera();
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

void dealWithCollisions() 
{
	for (auto &enemy : enemies) 
	{
		if (enemy) 
		{
			if (dynamicsWorld->getPairCache()->findPair(player->playerRigidBody->getBroadphaseProxy(), enemy->enemyRigidBody->getBroadphaseProxy())) 
			{
				player->takeDmg(enemy->dmg);
			}
			for (auto &bullet : bullets) 
			{
				if (dynamicsWorld->getPairCache()->findPair(bullet->getBroadphaseProxy(), enemy->enemyRigidBody->getBroadphaseProxy())) 
				{
					dynamicsWorld->removeRigidBody(bullet);
					bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());

					if (enemy->hp - player->dmg > 0) 
					{
						enemy->takeDmg(player->dmg);
					}
					else 
					{
						dynamicsWorld->removeRigidBody(enemy->enemyRigidBody);
						enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
					}
				}
			}
		}
	}
}

void playerShoot()
{
	static bool blockLeft = false;
	static sf::Clock timer = sf::Clock();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !blockLeft)
	{
		bullets.push_back(new btRigidBody(btRigidBody::btRigidBodyConstructionInfo(btScalar(0.2), new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1),
			btVector3((btScalar)cam->pointToLookAt.x, (btScalar)(cam->pointToLookAt.y + 0.2), (btScalar)cam->pointToLookAt.z))), new btSphereShape((btScalar)0.2), btVector3(1, 1, 1))));

		bullets.back()->applyCentralImpulse(btVector3(cam->lookDirection.x * 10, 0, cam->lookDirection.z * 10));
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