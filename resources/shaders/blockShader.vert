#version 460

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 atexCoords;
layout (location = 2) in vec3 aNormal;
layout (location = 3) in mat4 model;
layout (location = 7) in float aBlockType;

uniform mat4 projection;
uniform mat4 view;

out float BlockType;
out vec2 texCoords;
out vec3 normal;
out vec3 position;

void main()
{
    BlockType = aBlockType;
    texCoords = atexCoords;
    normal = aNormal;
    position = vec3(model[3][0], model[3][1], model[3][2]);
    gl_Position = projection * view * model * vec4(aPos, 1); 
}