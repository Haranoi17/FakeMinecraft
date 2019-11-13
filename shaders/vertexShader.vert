//uzywam tego bo w wyzszych wersjach trzeba przekazywac swoje macierze wrrrr....
#version 140

uniform vec3 aPos;

void main()
{
    aPos = vec3(0,0.5,1);
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex * vec4(aPos, 1);
}