#include <reRenderWorld.hpp>
#include <externs.hpp>

void prepareMatrices()
{
    if(!preparingMatrices)
    {
        preparingMatrices = true;
        delete[] matrices;
        delete[] blockTypes;
        generatedWorld.prepareToDraw(player);
        
        matrices = new glm::mat4[generatedWorld.ammountToDraw];
        blockTypes = new float[generatedWorld.ammountToDraw];
        int iterator = 0;
        for(Block *block : generatedWorld.blocksToDraw)
        {
            if(block->type != blockType::air)
            {
                blockTypes[iterator] = block->type;
                matrices[iterator] = glm::translate(glm::mat4(1), glm::vec3(block->position.x, block->position.y, block->position.z));;
                iterator++;
            }
        }
        matricesReady = true;
        preparingMatrices = false;
    }
}

void reRenderWorld()
{
    if(matricesReady)
    {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, generatedWorld.ammountToDraw * sizeof(glm::mat4), matrices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)0);
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)sizeof(glm::vec4));
        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(2*sizeof(glm::vec4)));
        glEnableVertexAttribArray(6);
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(3*sizeof(glm::vec4)));
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, generatedWorld.ammountToDraw * sizeof(float), blockTypes, GL_STATIC_DRAW);
        glEnableVertexAttribArray(7);
        glVertexAttribPointer(7, 1, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0);

        glVertexAttribDivisor(3, 1);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);
        glVertexAttribDivisor(7, 1);
    
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        matricesReady = false;
    }
}