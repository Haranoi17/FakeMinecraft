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
    
    if(input.getMouseLeft() && !input.getMouseRight())
    {
        if(checkDestroyPossibility(x, y, z))
        {
            timePassed += Timer.getElapsedTime().asSeconds();
            if(generatedWorld.blocks[x][y][z].type != blockType::air && timePassed > 0.5)
            {
                player.slots.push_back(generatedWorld.blocks[x][y][z].type);
                generatedWorld.blocks[x][y][z].type = blockType::air;
                matricePreparationThread.launch();
                //prepareMatrices();
                timePassed = 0;
            }
        }
    }

    if(input.getMouseRight() && !input.getMouseLeft())
    {
        if(checkPlacePossibility(x, y, z))
        {
            timePassed += Timer.getElapsedTime().asSeconds();
            if(player.slots.size() && timePassed > 0.2)
            {
                blockType tempType = player.slots.back();
                player.slots.pop_back();
                generatedWorld.blocks[x][y][z].type = tempType;
                //prepareMatrices();
                matricePreparationThread.launch();
                timePassed = 0;
            }
        }
    }

    if(!input.getMouseLeft() && !input.getMouseRight())
    {
        timePassed = 0;
    }
    Timer.restart();
}
