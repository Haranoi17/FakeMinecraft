#include <externs.hpp>
#include <functions.hpp> //drawScreen is already here

void initScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor((GLclampf)0.8, (GLclampf)0.8, (GLclampf)0.8, 1);
	glLoadIdentity();
	cam->moveCamera();
}

void drawLightSphere()
{
	glColor3f((GLfloat)0.3, (GLfloat)0.2, (GLfloat)0.3);
	glPushMatrix();
		glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
		gluSphere(quad,0.2,20,20);
	glPopMatrix();
}

void drawEnemy(Enemy *enemy)
{
	glPushMatrix();
		enemy->enemyRigidBody->getMotionState()->getWorldTransform(trans);
		glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
		glColor3f(1, enemy->hp/100.0f, enemy->hp/100.0f);
		glutSolidCube(1);
	glPopMatrix();
}

void drawGround()
{
	glPushMatrix();
		glScalef(10,0.2,10);
		glutSolidCube(1);
	glPopMatrix();
}

void drawBullet(btRigidBody *bullet)
{
	glPushMatrix();
		bullet->getMotionState()->getWorldTransform(trans);
		glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
		glScalef((GLfloat)0.2, (GLfloat)0.2, (GLfloat)0.2);
		glutSolidCube(1);
	glPopMatrix();
}

void drawPlayer()
{
	glPushMatrix();
		player->playerRigidBody->getMotionState()->getWorldTransform(trans);
		glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
		glColor4f(1, player->hp / 100.0f, player->hp / 100.0f, 0.5);
		glutSolidCube(1);
	glPopMatrix();  
}

void drawTestingStuff()
{
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(3, 4, 0);
	gluSphere(quad,2,40, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-3, 4, 0);
	glRotatef(animationTimer.getElapsedTime().asMicroseconds()/10000.0 ,1,0,0);
	gluCylinder(quad,0,3,4,10,10);
	glPopMatrix();
}

void drawScreen()
{
	
	initScreen();
	
	glUseProgram(program);
	
	drawGround();

	for (auto &enemy : enemies)
	{
		drawEnemy(enemy);
	}

	for (auto &bullet : bullets)
	{
		drawBullet(bullet);
	}

	drawTestingStuff();
	
	drawPlayer();
	
	glUseProgram(0);

	drawAxis();
}

//opacity template for drawing object. Draw thing as LAST! element to ensure proper positioning

	// glEnable(GL_BLEND);
	// __glewBlendEquation(GL_ONE_MINUS_SRC_ALPHA);
	// glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
	// here draw your stuff
	// glDisable(GL_BLEND);