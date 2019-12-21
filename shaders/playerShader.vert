#version 460

layout (location = 0) in vec3 aPos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform float gunScale;
uniform float drawGun;

void main()
{
    if(drawGun == 1)
    {
        gl_Position = projection * view * model * vec4((aPos.x - 5)*gunScale,(aPos.y - 5)*gunScale, (aPos.z - 5)*gunScale, 1);
    }
    else
    {
        gl_Position = projection * view * model * vec4(aPos/2, 1); 
    }
}