#version 460

out vec4 FragColor;

in vec2 texCoords;
in vec3 normal;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform sampler2D tex2;

void main()
{
 
    if(normal.y > 0)
    {
        FragColor = texture(tex0, texCoords);
    }
    if(normal.x != 0 || normal.z != 0)
    {
        FragColor = texture(tex1, texCoords);
    }
    if(normal.y < 0)
    {
        FragColor = texture(tex2, texCoords);
    }
}