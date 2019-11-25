#include <externs.hpp>
#include <functions.hpp> //drawScreen is already here

void drawDirtBlock()
{
	sf::Texture::bind(&grassTopTexture);
	glBegin(GL_QUADS);
	// top
	glTexCoord2f(0,0);glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1,0);glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1,1);glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0,1);glVertex3f(-0.5f, 0.5f, -0.5f);
	
	glEnd();
	
	sf::Texture::bind(&grassTexture);
	glBegin(GL_QUADS);
	// front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0,1);glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1,1);glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1,0);glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0,0);glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	glBegin(GL_QUADS);
	// right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0,1);glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1,1);glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1,0);glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0,0);glVertex3f(0.5f, 0.5f, 0.5f);
	glEnd();
	
	glBegin(GL_QUADS);
	// left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0,1);glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1,1);glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1,0);glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0,0);glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();	

	glBegin(GL_QUADS);
	// back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0,1);glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1,1);glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1,0);glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0,0);glVertex3f(-0.5f, 0.5f, -0.5f);
	
	glEnd();
	
	sf::Texture::bind(&dirtTexture);
	glBegin(GL_QUADS);
	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0,0);glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1,0);glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1,1);glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(0,1);glVertex3f(0.5f, -0.5f, -0.5f);
	
	glEnd();

	sf::Texture::bind(NULL);
}


void drawLightSphere()
{
	glColor3f((GLfloat)0.3, (GLfloat)0.2, (GLfloat)0.3);
	glPushMatrix();
		glTranslatef(lightPos[0],lightPos[1],lightPos[2]);
		gluSphere(quad,0.2,20,20);
	glPopMatrix();
}

void drawBlock(Enemy *enemy)
{
	glPushMatrix();
		glTranslatef(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ());
		glColor3f(1, enemy->hp/100.0f, enemy->hp/100.0f);
		drawDirtBlock();
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
		glTranslatef(player->trans.getOrigin().getX(), player->trans.getOrigin().getY(), player->trans.getOrigin().getZ());
		glColor4f(1, player->hp / 100.0f, player->hp / 100.0f, 0.5);
		glutSolidCube(1);
	glPopMatrix();  
}

void drawAxis()
{
	glPushMatrix();
	
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
	glPopMatrix();
}

void drawCrosshair()
{


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


	glEnable(GL_BLEND);
	
	glColor4f(1,1,1,0.5);
	glPushMatrix();
	glTranslatef(gunPosition.x, gunPosition.y, gunPosition.z);
	gluSphere(quad, 0.2, 10, 10);
	glPopMatrix();

	glDisable(GL_BLEND);

//crosshair
	sf::Texture::bind(&crosshairTexture);
	//glDisable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0); glVertex2f(0,0);
	glTexCoord2f(1,0); glVertex2f(1,0);
	glTexCoord2f(1,1); glVertex2f(1,1);
	glTexCoord2f(0,1); glVertex2f(0,1);
	glEnd();
	glDisable(GL_BLEND);
	//glEnable(GL_DEPTH_TEST);
	
	sf::Texture::bind(NULL);
	glMatrixMode(GL_MODELVIEW);

}

// void drawWorld()
// {
// 	for(int i = 0; i < generatedWorld.width; i++)
// 	{
// 		for(int j = 0; j < generatedWorld.depth; j++)
// 		{
// 			for(int k = 0; k < generatedWorld.heights[i][j]; k++)
// 			{
// 				glPushMatrix();
// 				glTranslatef(i,k,j);
// 				drawDirtBlock();
// 				glPopMatrix();
// 			}
// 		}
// 	}
// }



void drawScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor((GLclampf)0.8, (GLclampf)0.8, (GLclampf)0.8, 1);
	
	drawGround();


	
	//drawWorld();
	drawAxis();
	for (auto &block : blocks)
	{
		 block->RigidBody->getMotionState()->getWorldTransform(trans);
		 btVector3 dist = btVector3(trans.getOrigin().getX() - player->trans.getOrigin().getX(), trans.getOrigin().getY() - player->trans.getOrigin().getY(), trans.getOrigin().getZ() - player->trans.getOrigin().getZ());

		
		// if(dist.length2() < drawDistance * drawDistance)
		// {
			drawBlock(block);
		// }
	}

	for (auto &bullet : bullets)
	{
		drawBullet(bullet);
	}

	drawTestingStuff();
	drawPlayer();
	//drawCrosshair();
}

//opacity template for drawing object. Draw thing as LAST! element to ensure proper positioning

	// glEnable(GL_BLEND);
	// __glewBlendEquation(GL_ONE_MINUS_SRC_ALPHA);
	// glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
	// here draw your stuff
	// glDisable(GL_BLEND);