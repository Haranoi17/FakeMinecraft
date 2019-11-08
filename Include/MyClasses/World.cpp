#include <World.hpp>
#include <random>

World::World(int seed)
{
    this->width = 100;
    this->depth = 10;
    std::srand(seed);

    this->heights = new int**[width]; //tablica wskaznikow

    for(int i = 0; i < width; i++)
    {
        this->heights[i] = new int*[depth];
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < depth; j++)
        {
            this->heights[i][j] = new int;
        }
    }

    this->blockCoords = new sf::Vector3i**[100];
    
    for(int i = 0; i < width; i++)
    {
        this->blockCoords[i] = new sf::Vector3i*[100];
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < depth; j++)
        {
            *this->heights[i][j] = (int)(((float)std::rand()/RAND_MAX) * 20);
            this->blockCoords[i][j] = new sf::Vector3i[*this->heights[i][j]];
        }
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < depth; j++)
        {
            for(int k = 0; k < *this->heights[i][j]; k++)
            {
                this->blockCoords[i][j][k] = sf::Vector3i(i,j,k);
            }
        }
    }
}

World::~World()
{

}

