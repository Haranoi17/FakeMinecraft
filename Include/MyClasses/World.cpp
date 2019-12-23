#include <World.hpp>
#include <random>
#include <iostream>

World::World(int seed)
    :dimentions(sf::Vector3f(100,256,100))
{
    alocateMemory();
    fillBlockTypes();
    prepareToDraw();
}

World::~World()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;
    
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

void World::fillBlockTypes()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;


    for(int i = 1; i < x - 1; i++)
    {
        for(int j = 1; j < y/2; j++)
        {
            for(int k = 1; k < z - 1; k++)
            {
                blocks[i][j][k].type = blockType::dirt;
            }
        }
    }
}

void World::prepareToDraw()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;
    
    int ammount = 0;
    if(blocksToDraw.size())
    {
        blocksToDraw.clear();
    }

    for(int i = 1; i < x - 1; i++)
    {
        for(int j = 1; j < y - 1; j++)
        {
            for(int k = 1; k < z - 1; k++)
            {
                if(checkAir(blocks[i][j][k].position))
                {
                    blocksToDraw.push_back(blocks[i][j][k]);
                    ammount++; 
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
