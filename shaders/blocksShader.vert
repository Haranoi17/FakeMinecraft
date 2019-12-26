#version 460

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 atexCoords;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in mat4 model;
layout (location = 7) in float aBlockType;

uniform mat4 projection;
uniform mat4 view;

out float blockType;
out vec2 texCoords;
out vec3 normal;

void main()
{
    blockType = aBlockType;
    texCoords = atexCoords;
    normal = aNormal;
    gl_Position = projection * view * model * vec4(aPos, 1); 
}