#version 460

out vec4 FragColor;

uniform vec2 texCoord;
uniform sampler2D texture;

void main()
{
   FragColor = texture(texture, texCoord);
}