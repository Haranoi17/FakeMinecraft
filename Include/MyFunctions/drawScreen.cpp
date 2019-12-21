#include <externs.hpp>
#include <functions.hpp> //drawScreen is already here






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


void initScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor((GLclampf)0.6, (GLclampf)0.6, (GLclampf)0.6, 1);
	glLoadIdentity();
	view = player.cam.moveCamera();
}


void drawScreen(Shader blocksShader, Shader playerShader)
{
	initScreen();

	playerShader.use();
	playerShader.setMat4(playerShader.viewLoc, view);
	playerShader.setMat4(playerShader.projectionLoc, projection);
	
	model = glm::mat4(1);
	playerShader.setMat4(playerShader.modelLoc, model);
	drawAxis();

	model = glm::translate(glm::mat4(1), glm::vec3(player.pos.x, player.pos.y, player.pos.z));
	playerShader.setMat4(playerShader.modelLoc, model);
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 0);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(player.gunPos.x, player.gunPos.y, player.gunPos.z))); 
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "gunScale"), 0.05);
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 1);

	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	

	blocksShader.use();
	blocksShader.setMat4(blocksShader.viewLoc, view);
	blocksShader.setMat4(blocksShader.projectionLoc, projection);

	glBindVertexArray(VAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 36, generatedWorld.ammountToDraw);

	glUseProgram(0);

	// for(auto &block : blocks)
	// {
	// 	glBindVertexArray(VAO);
	// 	glDrawArrays(GL_TRIANGLES, 0, 36);
	// 	glBindVertexArray(0);	
	// }

	// for (auto &bullet : bullets)
	// {
	// 	trans = bullet->getWorldTransform();
	// 	model = glm::translate(glm::mat4(1), glm::vec3(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ()));
	// 	glutSolidCube(0.2);
	// }

	// model = glm::translate(glm::mat4(1), glm::vec3(gunPosition.x, gunPosition.y, gunPosition.z));
	// blocksShader.setMat4(modelLoc, model);
	// gluSphere(quad, 0.2, 10, 10);

	
	// model = glm::translate(glm::mat4(1), glm::vec3(lightPos[0], lightPos[1], lightPos[2]));
	// gluSphere(quad,0.2,20,20);
	
}

//opacity template for drawing object. Draw thing as LAST! element to ensure proper positioning

	// glEnable(GL_BLEND);
	// __glewBlendEquation(GL_ONE_MINUS_SRC_ALPHA);
	// glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
	// here draw your stuff
	// glDisable(GL_BLEND);