#include <World.hpp>
#include <random>
#include <iostream>
#include <math.h>
#include <random>
#include <vectorOperations.hpp>

World::World(int seed)
    :dimentions(sf::Vector3f(1000,100,1000))
{
    alocateMemory();
    generateTerrain();
    fillBlockTypes();
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

void World::fillBlockTypes()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;


    for(int i = 1; i < x - 1; i++)
    {
        for(int k = 1; k < z; k++)
        {
            for(int j = 1; j < heights[i][k]; j++)
            {
                blocks[i][j][k].type = blockType::dirt;
            }
        }
    }
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

    int r = 50;
    if(playerPos.x - r <= 1){leftBound = 0;} else {leftBound = playerPos.x - r;}
    if(playerPos.y - r <= 1){bottomBound = 0;} else {bottomBound = playerPos.y - r;}
    if(playerPos.z - r <= 1){backBound = 0;} else {backBound = playerPos.z - r;}

    if(playerPos.x + r >= dimentions.x - 1){rightBound = dimentions.x;} else {rightBound = playerPos.x + r;}
    if(playerPos.y + r >= dimentions.y - 1){topBound = dimentions.y;} else {topBound = playerPos.y + r;}
    if(playerPos.z + r >= dimentions.z - 1){frontBound = dimentions.z;} else {frontBound = playerPos.z + r;}

    for(int i = leftBound; i < rightBound; i++)
    {
        for(int j = bottomBound; j < topBound; j++)
        {
            for(int k = backBound; k < frontBound; k++)
            {
                if(checkAir(blocks[i][j][k].position))
                {
                    distanceVector = sf::Vector3f(i, j, k) - playerPos;
                    if(vec3Length(distanceVector.x, distanceVector.y, distanceVector.z) < 50)
                    {
                        blocksToDraw.push_back(blocks[i][j][k]);
                        ammount++;
                    }
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
