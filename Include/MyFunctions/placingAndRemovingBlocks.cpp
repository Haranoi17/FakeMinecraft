#include <placingAndRemovingBlocks.hpp>
#include <externs.hpp>
#include <reRenderWorld.hpp>
#include <math.h>

bool checkplacePossibility(const int &x, const int &y, const int &z)
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

void placingAndRemovingBlocks()
{
    int x = player.gunPos.x + 0.25;
    int y = player.gunPos.y + 0.25;
    int z = player.gunPos.z + 0.25;
    if(input.getMouseLeft())
    {
        if(generatedWorld.blocks[x][y][z].type != blockType::air)
        {
            player.slots.push_back(generatedWorld.blocks[x][y][z].type);
            generatedWorld.blocks[x][y][z].type = blockType::air;
        }
    }

    if(input.getMouseRight())
    {
        if(checkplacePossibility(x, y, z))
        {
            std::cout << player.slots.size() << std::endl;
            if(player.slots.size())
            {
                blockType tempType = player.slots.back();
                player.slots.pop_back();
                generatedWorld.blocks[x][y][z].type = tempType;
            }
        }
    }
}
