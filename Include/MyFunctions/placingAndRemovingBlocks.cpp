#include <placingAndRemovingBlocks.hpp>
#include <externs.hpp>
#include <reRenderWorld.hpp>

void placingAndRemovingBlocks()
{
    if(input.getMouseLeft())
    {
        if(player.gunPos.x > 0 && player.gunPos.x < generatedWorld.dimentions.x)
        {
            if(player.gunPos.y > 0 && player.gunPos.y < generatedWorld.dimentions.y)
            {
                if(player.gunPos.z > 0 && player.gunPos.z < generatedWorld.dimentions.z)
                {
                    if(generatedWorld.blocks[(int)(player.gunPos.x + 0.25)][(int)(player.gunPos.y + 0.25)][(int)(player.gunPos.z + 0.25)].type != blockType::air)
                    {
                        player.slots.push_back(generatedWorld.blocks[(int)(player.gunPos.x + 0.25)][(int)(player.gunPos.y + 0.25)][(int)(player.gunPos.z + 0.25)].type);
                    }
                    generatedWorld.blocks[(int)(player.gunPos.x + 0.25)][(int)(player.gunPos.y + 0.25)][(int)(player.gunPos.z + 0.25)].type = blockType::air;
                    reRenderWorld();
                }
            }
        }
    }
    if(input.getMouseRight())
    {
        if(player.gunPos.x > 0 && player.gunPos.x < generatedWorld.dimentions.x)
        {
            if(player.gunPos.y > 0 && player.gunPos.y < generatedWorld.dimentions.y)
            {
                if(player.gunPos.z > 0 && player.gunPos.z < generatedWorld.dimentions.z)
                {
                    
                    if(generatedWorld.blocks[(int)(player.gunPos.x + 0.25)][(int)(player.gunPos.y + 0.25)][(int)(player.gunPos.z + 0.25)].type == blockType::air)
                    {

                        blockType tempType = player.slots.back();
                        if(player.slots.size())
                        {
                            player.slots.pop_back();
                        }
                        generatedWorld.blocks[(int)(player.gunPos.x + 0.25)][(int)(player.gunPos.y + 0.25)][(int)(player.gunPos.z + 0.25)].type = tempType;
                        reRenderWorld();
                    }
                    
                }
            }
        }
    }
}