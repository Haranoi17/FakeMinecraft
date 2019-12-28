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
	view = player.cam.moveCamera();
}


void drawScreen()
{
	initScreen();

	playerShader.use();
	playerShader.setMat4(playerShader.viewLoc, view);
	playerShader.setMat4(playerShader.projectionLoc, projection);

	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 0);
	playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(player.cam.pos.x, player.cam.pos.y, player.cam.pos.z)));

	glDisable(GL_DEPTH_TEST);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glEnable(GL_DEPTH_TEST);
	
	// playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(player.pos.x, player.pos.y, player.pos.z))); 
	// playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 0);
	// glBindVertexArray(VAO);
	// glDrawArrays(GL_TRIANGLES, 0, 36);


	//model = glm::translate(glm::mat4(1), glm::vec3(player.pos.x, player.pos.y, player.pos.z));
	playerShader.setMat4(playerShader.modelLoc, glm::translate(glm::mat4(1), glm::vec3(player.gunPos.x, player.gunPos.y, player.gunPos.z))); 
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "gunScale"), 0.05);
	playerShader.setFloat(glGetUniformLocation(playerShader.getID(), "drawGun"), 1);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	blocksShader.use();
	blocksShader.setMat4(blocksShader.viewLoc, view);
	blocksShader.setMat4(blocksShader.projectionLoc, projection);

	glBindVertexArray(VAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 36, generatedWorld.ammountToDraw);

	glUseProgram(0);
	glBindVertexArray(0);
}