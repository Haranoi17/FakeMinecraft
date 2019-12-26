#version 460

out vec4 FragColor;

in vec2 texCoords;
in vec3 normal;
in float blockType;

int type;
uniform sampler2D grassTop;
uniform sampler2D grassSide;
uniform sampler2D dirt;
uniform sampler2D stone;
uniform sampler2D wood;
uniform sampler2D leaves;

void main()
{
    if(blockType > 0.5 && blockType < 1.5){type = 1;}
    if(blockType > 1.5 && blockType < 2.5){type = 2;}
    if(blockType > 2.5 && blockType < 3.5){type = 3;} 
    if(blockType > 3.5 && blockType < 4.5){type = 4;}
    
    switch(type)
    {
        case 1:
        {
            if(normal.y > 0)
            {
                FragColor = texture(grassTop, texCoords);
            }
            if(normal.x != 0 || normal.z != 0)
            {
                FragColor = texture(grassSide, texCoords);
            }
            if(normal.y < 0)
            {
                FragColor = texture(dirt, texCoords);
            }
            break;
        }
        case 2:
        {
            FragColor = texture(stone, texCoords);
            break;
        }
        case 3:
        {
            FragColor = texture(wood, texCoords);
            break;
        }
        case 4:
        {
            FragColor = texture(leaves, texCoords);
            break;
        }
        default:
        {
            FragColor = vec4(1,1,1,1);
            break;
        }
    }
} 