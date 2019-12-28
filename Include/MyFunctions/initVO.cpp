#include <initVO.hpp>
#include <externs.hpp>
#include <functions.hpp>

void initVO()
{
	glGenBuffers(3, VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData), cubeData, GL_STREAM_DRAW);

    glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(5 * sizeof(float)));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    matrices = new glm::mat4[1];
    blockTypes = new float[1];
    prepareMatrices();
    reRenderWorld();
   
}
