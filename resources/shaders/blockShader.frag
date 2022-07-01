#version 460

out vec4 FragColor;

in vec2 texCoords;
in vec3 normal;
in vec3 position;
in float BlockType;

int type;
uniform sampler2D grassTop;
uniform sampler2D grassSide;
uniform sampler2D dirt;
uniform sampler2D stone;
uniform sampler2D wood;
uniform sampler2D leaves;

uniform float lightX;
uniform float lightY;
uniform float lightZ;

void main()
{
    vec4 texColor;
    vec3 lightPos = vec3(lightX, lightY, lightZ);
    vec3 toLight = lightPos - position;
    vec3 toLightNorm = normalize(lightPos - position);
    if(BlockType > 0.5 && BlockType < 1.5){type = 1;}
    if(BlockType > 1.5 && BlockType < 2.5){type = 2;}
    if(BlockType > 2.5 && BlockType < 3.5){type = 3;} 
    if(BlockType > 3.5 && BlockType < 4.5){type = 4;}


    switch(type)
    {
        case 1:
        {
            if(normal.y > 0)
            {
                texColor = texture(grassTop, texCoords);
            }
            if(normal.x != 0 || normal.z != 0)
            {
                texColor = texture(grassSide, texCoords);
            }
            if(normal.y < 0)
            {
                texColor = texture(dirt, texCoords);
            }
            break;
        }
        case 2:
        {
            texColor = texture(stone, texCoords);
            break;
        }
        case 3:
        {
            texColor = texture(wood, texCoords);
            break;
        }
        case 4:
        {
            texColor = texture(leaves, texCoords);
            break;
        }
        default:
        {
            texColor = vec4(1,1,1,1);
            break;
        }
    }

    texColor.rgb *= (1 + dot(toLightNorm, normal))/(5 + length(toLight)/8);
    FragColor = texColor;
} 