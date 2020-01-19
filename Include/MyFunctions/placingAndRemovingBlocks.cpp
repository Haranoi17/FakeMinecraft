#include <placingAndRemovingBlocks.hpp>
#include <externs.hpp>
#include <reRenderWorld.hpp>
#include <math.h>

bool checkPlacePossibility(const int &x, const int &y, const int &z)
{

    
    if( generatedWorld.blocks[x][y][z].type == blockType::air && (
        generatedWorld.blocks[x-1][y][z].type != blockType::air || 
        generatedWorld.blocks[x][y-1][z].type != blockType::air || 
        generatedWorld.blocks[x][y][z-1].type != blockType::air || 
        generatedWorld.blocks[x+1][y][z].type != blockType::air ||
        generatedWorld.blocks[x][y+1][z].type != blockType::air || 
        generatedWorld.blocks[x][y][z+1].type != blockType::air))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkDestroyPossibility(const int &x, const int &y, const int &z)
{

    
    if( generatedWorld.blocks[x][y][z].type != blockType::air && (
        generatedWorld.blocks[x-1][y][z].type == blockType::air || 
        generatedWorld.blocks[x][y-1][z].type == blockType::air || 
        generatedWorld.blocks[x][y][z-1].type == blockType::air || 
        generatedWorld.blocks[x+1][y][z].type == blockType::air ||
        generatedWorld.blocks[x][y+1][z].type == blockType::air || 
        generatedWorld.blocks[x][y][z+1].type == blockType::air))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void placingAndRemovingBlocks()
{
    static sf::Clock Timer = sf::Clock();
    static float timePassed = 0;

    int x = player.gunPos.x + 0.25;
    int y = player.gunPos.y + 0.25;
    int z = player.gunPos.z + 0.25;
    
    if(input.getMouseLeft() && !input.getMouseRight() && player.pos.y > 5)
    {
        if(checkDestroyPossibility(x, y, z))
        {
            timePassed += Timer.getElapsedTime().asSeconds();
            if(generatedWorld.blocks[x][y][z].type != blockType::air)
            {
                for(Block* block : generatedWorld.blocksNextToPlayer)
                {
                    if(block->position.x == x && block->position.y == y && block->position.z == z)
                    {
                        player.slots.push_back(block->type);
                        block->type = blockType::air;
                    }
                }
                timePassed = 0;
                needToRefreshBlocks = true;
            }
        }
    }

    if(input.getMouseRight() && !input.getMouseLeft())
    {
        if(checkPlacePossibility(x, y, z))
        {
            timePassed += Timer.getElapsedTime().asSeconds();
            if(player.slots.size())
            {
                std::cout << "a";
                blockType tempType = player.slots.back();
                player.slots.pop_back();
                generatedWorld.blocks[x][y][z].type = tempType;
                timePassed = 0;
                needToRefreshBlocks = true;
            }
        }
    }

    if(!input.getMouseLeft() && !input.getMouseRight())
    {
        timePassed = 0;
    }
    Timer.restart();
}
