#include <World.hpp>
#include <random>
#include <iostream>
#include <math.h>
#include <random>
#include <Vector3f.hpp>

World::World()
    : dimentions{1000, 100, 1000}
{
    alocateMemory();
    generateTerrain();
    generateTrees();
    fillBlockTypes();
    Player temp;
    temp.position = Vector3f(dimentions.x / 2, heights[(int)dimentions.x / 2][(int)dimentions.z / 2], dimentions.z / 2);
    prepareToDraw(temp);
}

World::~World()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;

    for (int i = 0; i < x; i++)
    {
        delete[] heights[i];
    }

    delete[] heights;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            delete[] blocks[i][j];
        }
    }

    for (int i = 0; i < x; i++)
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

    heights = new float *[x];
    for (int i = 0; i < x; i++)
    {
        heights[i] = new float[z];
    }
    blocks = new Block **[x];

    for (int i = 0; i < x; i++)
    {
        blocks[i] = new Block *[y];
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            blocks[i][j] = new Block[z];
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                blocks[i][j][k] = Block(Vector3f(i, j, k), BlockType::Air);
            }
        }
    }
}

void World::generateTerrain()
{
    int x = dimentions.x;
    int z = dimentions.z;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < z; j++)
        {
            int newHeight = 10 + 15 * pow(sin((float)i / 100), 2) + 20 * pow(cos((float)j / 100), 2) + 5 * pow(sin((float)(i) / 20), 2);

            if (newHeight >= dimentions.y)
            {
                newHeight = dimentions.y;
            }
            heights[i][j] = newHeight;
        }
    }
}

void World::generateTrees()
{
    int x = dimentions.x;
    int z = dimentions.z;

    for (int i = 10; i < x - 10; i++)
    {
        for (int j = 10; j < z - 10; j++)
        {
            if (i % 20 == 0 && j % 50 == 0)
            {
                int k = (int)heights[i][j];
                // pien
                blocks[i][k][j].m_type = BlockType::Wood;
                blocks[i][k + 1][j].m_type = BlockType::Wood;
                blocks[i][k + 2][j].m_type = BlockType::Wood;
                blocks[i][k + 3][j].m_type = BlockType::Wood;
                blocks[i][k + 4][j].m_type = BlockType::Wood;
                // liscie
                blocks[i][k + 5][j].m_type = BlockType::Leaves;
                blocks[i - 1][k + 5][j].m_type = BlockType::Leaves;
                blocks[i - 1][k + 5][j - 1].m_type = BlockType::Leaves;
                blocks[i - 1][k + 5][j + 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 5][j].m_type = BlockType::Leaves;
                blocks[i + 1][k + 5][j - 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 5][j + 1].m_type = BlockType::Leaves;
                blocks[i][k + 5][j + 1].m_type = BlockType::Leaves;
                blocks[i][k + 5][j - 1].m_type = BlockType::Leaves;

                blocks[i - 1][k + 4][j].m_type = BlockType::Leaves;
                blocks[i - 1][k + 4][j - 1].m_type = BlockType::Leaves;
                blocks[i - 1][k + 4][j + 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 4][j - 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 4][j + 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 4][j].m_type = BlockType::Leaves;
                blocks[i][k + 4][j - 1].m_type = BlockType::Leaves;
                blocks[i][k + 4][j + 1].m_type = BlockType::Leaves;

                blocks[i - 1][k + 3][j].m_type = BlockType::Leaves;
                blocks[i - 1][k + 3][j - 1].m_type = BlockType::Leaves;
                blocks[i - 1][k + 3][j + 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 3][j - 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 3][j + 1].m_type = BlockType::Leaves;
                blocks[i + 1][k + 3][j].m_type = BlockType::Leaves;
                blocks[i][k + 3][j - 1].m_type = BlockType::Leaves;
                blocks[i][k + 3][j + 1].m_type = BlockType::Leaves;
            }
        }
    }
}

void World::fillBlockTypes()
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;

    for (int i = 1; i < x - 1; i++)
    {
        for (int k = 1; k < z; k++)
        {
            for (int j = 1; j < heights[i][k] / 2; j++)
            {
                blocks[i][j][k].m_type = BlockType::Stone;
            }
        }
    }

    for (int i = 1; i < x - 1; i++)
    {
        for (int k = 1; k < z; k++)
        {
            for (int j = heights[i][k] / 2; j < heights[i][k]; j++)
            {
                blocks[i][j][k].m_type = BlockType::Dirt;
            }
        }
    }
}

void World::prepareBlocksWithAirTouch(const Player &player)
{
    int x = dimentions.x;
    int y = dimentions.y;
    int z = dimentions.z;
    Vector3f distanceVector;

    if (blocksWithAirTouch.size())
    {
        blocksWithAirTouch.clear();
    }

    int leftBound;
    int rightBound;
    int topBound;
    int bottomBound;
    int frontBound;
    int backBound;

    int r = 100;
    if (player.position.x - r <= 1)
    {
        leftBound = 0;
    }
    else
    {
        leftBound = player.position.x - r;
    }
    if (player.position.y - r <= 1)
    {
        bottomBound = 0;
    }
    else
    {
        bottomBound = player.position.y - r;
    }
    if (player.position.z - r <= 1)
    {
        backBound = 0;
    }
    else
    {
        backBound = player.position.z - r;
    }

    if (player.position.x + r >= dimentions.x - 1)
    {
        rightBound = dimentions.x;
    }
    else
    {
        rightBound = player.position.x + r;
    }
    if (player.position.y + r >= dimentions.y - 1)
    {
        topBound = dimentions.y;
    }
    else
    {
        topBound = player.position.y + r;
    }
    if (player.position.z + r >= dimentions.z - 1)
    {
        frontBound = dimentions.z;
    }
    else
    {
        frontBound = player.position.z + r;
    }

    for (int i = leftBound; i < rightBound; i++)
    {
        for (int j = bottomBound; j < topBound; j++)
        {
            for (int k = backBound; k < frontBound; k++)
            {
                distanceVector = blocks[i][j][k].m_position - player.position;
                if (distanceVector.length() < 5)
                {
                    blocksNextToPlayer.push_back(&blocks[i][j][k]);
                }
                if (checkAir(blocks[i][j][k].m_position))
                {
                    blocksWithAirTouch.push_back(&blocks[i][j][k]);
                }
            }
        }
    }
}

void World::prepareToDraw(const Player &player)
{
    int ammount = 0;
    Vector3f distanceVector;
    bool signOfCosinus;
    int r = 150;

    if (blocksToDraw.size())
    {
        blocksToDraw.clear();
    }

    for (Block *block : blocksWithAirTouch)
    {
        distanceVector = block->m_position - player.position;
        signOfCosinus = (player.cam.m_lookDirectionFlat.x * distanceVector.x + player.cam.m_lookDirectionFlat.z * distanceVector.z) >= -2;

        if (signOfCosinus && distanceVector.length() < r)
        {
            blocksToDraw.push_back(block);
            ammount++;
        }
    }
    ammountToDraw = ammount;
}

bool World::checkAir(const Vector3f &pos) const
{
    int x = pos.x;
    int y = pos.y;
    int z = pos.z;

    if (blocks[x][y][z].m_type == BlockType::Air)
    {
        return false;
    }

    if (blocks[x - 1][y - 1][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y - 1][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y - 1][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y - 1][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y - 1][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y - 1][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y - 1][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y - 1][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y - 1][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    // this block XD
    if (blocks[x][y][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y + 1][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y + 1][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x - 1][y + 1][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y + 1][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y + 1][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x][y + 1][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y + 1][z - 1].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y + 1][z].m_type == BlockType::Air)
    {
        return true;
    }
    if (blocks[x + 1][y + 1][z + 1].m_type == BlockType::Air)
    {
        return true;
    }
    return false;
}
