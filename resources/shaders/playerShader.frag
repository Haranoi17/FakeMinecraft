#version 460

out vec4 FragColor;

in vec2 texCoords;

uniform sampler2D tex0;

void main()
{
    FragColor = texture(tex0, texCoords);
    //FragColor = vec4(0,1,0,1);
}