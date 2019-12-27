#include <World.hpp>
#include <random>
#include <iostream>
#include <math.h>
#include <random>
#include <vectorOperations.hpp>

World::World(int seed)
    :dimentions(sf::Vector3f(100,100,100))
{
    alocateMemory();
    generateTerrain();
    generateTrees();
    fillBlockTypes();
    preparePossibleToDraw();
    std::cout << ammountPossibleToDraw << std::endl;
    prepareToDraw(sf::Vector3f(dimentions.x/2, heights[(int)dimentions.x/2][(int)dimentions.z/2], dimentions.z/2));
}

World::~World()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;

    for(int i = 0; i < x; i++)
    {
        delete[] heights[i];
    }

    delete[] heights;

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            delete[] blocks[i][j];
        }
    }

    for(int i = 0; i < x; i++)
    {
        delete[] blocks[i];
    }

    delete[] blocks;

    blocksToDraw.clear();
}


void World::alocateMemory()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;

    heights = new float*[x];
    for(int i = 0; i < x; i++)
    {
        heights[i] = new float[z];
    }
    blocks = new Block**[x];

    for(int i = 0; i < x; i++)
    {
        blocks[i] = new Block*[y];
    }

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            blocks[i][j] = new Block[z];
        }
    }

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
            {
                blocks[i][j][k] = Block(sf::Vector3f(i, j, k), blockType::air);
            }
        }
    }
}

void World::generateTerrain()
{
    int x = dimentions.x;
    int z = dimentions.z;

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < z; j++)
        {
            int newHeight = 20 + 20 *pow(sin((float)i/100), 2) +  20* pow(cos((float)j/100), 2) + 5 * pow(sin((float)(i)/20), 2);

            if(newHeight >= dimentions.y){newHeight = dimentions.y;}
            heights[i][j] = newHeight;
        }
    }
}

void World::generateTrees()
{
    int x = dimentions.x;
    int z = dimentions.z;

    for(int i = 10; i < x-10; i++)
    {
        for(int j = 10; j < z-10; j++)
        {
            if(i%20 == 0 && j %50 == 0)
            {
                int k = (int)heights[i][j];
                //pien
                blocks[i][k][j].type =  blockType::wood;
                blocks[i][k+1][j].type = blockType::wood;
                blocks[i][k+2][j].type = blockType::wood;
                blocks[i][k+3][j].type = blockType::wood;
                blocks[i][k+4][j].type = blockType::wood;
                //liscie
                blocks[i][k+5][j].type = blockType::leaves;
                blocks[i-1][k+5][j].type = blockType::leaves;
                blocks[i-1][k+5][j-1].type = blockType::leaves;
                blocks[i-1][k+5][j+1].type = blockType::leaves;
                blocks[i+1][k+5][j].type = blockType::leaves;
                blocks[i+1][k+5][j-1].type = blockType::leaves;
                blocks[i+1][k+5][j+1].type = blockType::leaves;
                blocks[i][k+5][j+1].type = blockType::leaves;
                blocks[i][k+5][j-1].type = blockType::leaves;
                
                blocks[i-1][k+4][j].type = blockType::leaves;
                blocks[i-1][k+4][j-1].type = blockType::leaves;
                blocks[i-1][k+4][j+1].type = blockType::leaves;
                blocks[i+1][k+4][j-1].type = blockType::leaves;
                blocks[i+1][k+4][j+1].type = blockType::leaves;
                blocks[i+1][k+4][j].type = blockType::leaves;
                blocks[i][k+4][j-1].type = blockType::leaves;
                blocks[i][k+4][j+1].type = blockType::leaves;

                 
                blocks[i-1][k+3][j].type = blockType::leaves;
                blocks[i-1][k+3][j-1].type = blockType::leaves;
                blocks[i-1][k+3][j+1].type = blockType::leaves;
                blocks[i+1][k+3][j-1].type = blockType::leaves;
                blocks[i+1][k+3][j+1].type = blockType::leaves;
                blocks[i+1][k+3][j].type = blockType::leaves;
                blocks[i][k+3][j-1].type = blockType::leaves;
                blocks[i][k+3][j+1].type = blockType::leaves;
            }
        }
    }
}

void World::fillBlockTypes()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;


    for(int i = 1; i < x - 1; i++)
    {
        for(int k = 1; k < z; k++)
        {
            for(int j = 1; j < heights[i][k]/2; j++)
            {
                blocks[i][j][k].type = blockType::stone;
            }
        }
    }

    for(int i = 1; i < x - 1; i++)
    {
        for(int k = 1; k < z; k++)
        {
            for(int j = heights[i][k]/2; j < heights[i][k]; j++)
            {
                blocks[i][j][k].type = blockType::dirt;
            }
        }
    }
}

void World::preparePossibleToDraw()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;

    int ammount = 0;
    if(possibleToDraw.size())
    {
        possibleToDraw.clear();
    }

    for(int i = 5; i < dimentions.x-5; i++)
    {
        for(int j = 5; j < dimentions.y-5; j++)
        {
            for(int k = 5; k < dimentions.z-5; k++)
            {
                if(checkAir(blocks[i][j][k].position))
                {
                    possibleToDraw.push_back(&blocks[i][j][k]);
                    ammount++;
                }
            }
        }
    }
    ammountPossibleToDraw = ammount;
}

void World::prepareToDraw(const sf::Vector3f &playerPos)
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;
    sf::Vector3f distanceVector;

    int ammount = 0;
    if(blocksToDraw.size())
    {
        blocksToDraw.clear();
    }

    int leftBound;
    int rightBound;
    int topBound;
    int bottomBound;
    int frontBound;
    int backBound;

    int r = 100;
    if(playerPos.x - r <= 1){leftBound = 0;} else {leftBound = playerPos.x - r;}
    if(playerPos.y - r <= 1){bottomBound = 0;} else {bottomBound = playerPos.y - r;}
    if(playerPos.z - r <= 1){backBound = 0;} else {backBound = playerPos.z - r;}

    if(playerPos.x + r >= dimentions.x - 1){rightBound = dimentions.x;} else {rightBound = playerPos.x + r;}
    if(playerPos.y + r >= dimentions.y - 1){topBound = dimentions.y;} else {topBound = playerPos.y + r;}
    if(playerPos.z + r >= dimentions.z - 1){frontBound = dimentions.z;} else {frontBound = playerPos.z + r;}


    for(Block *block : possibleToDraw)
    {
        if(block->position.x > leftBound && block->position.x < rightBound)
        {
            if(block->position.y > bottomBound && block->position.y < topBound)
            {
                if(block->position.z < frontBound && block->position.z > backBound)
                {
                    blocksToDraw.push_back(block);
                }
            }
        }
    }
    ammountToDraw = ammount;
}

bool World::checkAir(const sf::Vector3f &pos) const
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;
    
    if(blocks[x][y][z].type == blockType::air)
    {
        return false;
    }
    
    if(blocks[x-1][y-1][z-1].type == blockType::air){return true;}
    if(blocks[x-1][y-1][z].type ==      blockType::air){return true;}
    if(blocks[x-1][y-1][z+1].type ==    blockType::air){return true;}
    if(blocks[x][y-1][z-1].type ==      blockType::air){return true;}
    if(blocks[x][y-1][z].type ==        blockType::air){return true;}
    if(blocks[x][y-1][z+1].type ==      blockType::air){return true;}
    if(blocks[x+1][y-1][z-1].type ==    blockType::air){return true;}
    if(blocks[x+1][y-1][z].type ==      blockType::air){return true;}
    if(blocks[x+1][y-1][z+1].type ==    blockType::air){return true;}
    if(blocks[x-1][y][z-1].type ==      blockType::air){return true;}
    if(blocks[x-1][y][z].type ==        blockType::air){return true;}
    if(blocks[x-1][y][z+1].type ==      blockType::air){return true;}
    if(blocks[x][y][z-1].type ==        blockType::air){return true;}
    //this block XD
    if(blocks[x][y][z+1].type ==        blockType::air){return true;}
    if(blocks[x+1][y][z-1].type ==      blockType::air){return true;}
    if(blocks[x+1][y][z].type ==        blockType::air){return true;}
    if(blocks[x+1][y][z+1].type ==      blockType::air){return true;}
    if(blocks[x-1][y+1][z-1].type ==    blockType::air){return true;}
    if(blocks[x-1][y+1][z].type ==      blockType::air){return true;}
    if(blocks[x-1][y+1][z+1].type ==    blockType::air){return true;}
    if(blocks[x][y+1][z-1].type ==      blockType::air){return true;}
    if(blocks[x][y+1][z].type ==        blockType::air){return true;}
    if(blocks[x][y+1][z+1].type ==      blockType::air){return true;}
    if(blocks[x+1][y+1][z-1].type ==    blockType::air){return true;}
    if(blocks[x+1][y+1][z].type ==      blockType::air){return true;}
    if(blocks[x+1][y+1][z+1].type ==    blockType::air){return true;}
    return false;
}
