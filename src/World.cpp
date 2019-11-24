#include <World.hpp>
#include <random>
#include <iostream>

World::World(int seed)
{
    std::cout << "Generating blocks" << std::endl;
    width = 40;
    depth = 40;
    std::srand(seed);

    heights = new int*[width]; //tablica wskaznikow

    for(int i = 0; i < width; i++)
    {
        heights[i] = new int[depth];
    }

    blockCoords = new btVector3**[width];
    
    for(int i = 0; i < width; i++)
    {
        blockCoords[i] = new btVector3*[depth];
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < depth; j++)
        {
            heights[i][j] = (int)(((float)std::rand()/RAND_MAX) * 20);
            blockCoords[i][j] = new btVector3[heights[i][j]];
        }
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < depth; j++)
        {
            for(int k = 0; k < heights[i][j]; k++)
            {
                blockCoords[i][j][k] = btVector3(i,k,j);
            }
        }
    }


    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < depth; j++)
        {
            for(int k = 0; k < heights[i][j]; k++)
            {
                positions.push_back(blockCoords[i][j][k]);
            }
        }
    }
}

World::~World()
{

}
