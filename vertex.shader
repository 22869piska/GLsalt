#version 330 core
layout (location = 0) in vec3 aPos;   
layout (location = 1) in vec3 aColor; //color postavit
 // layout (location = 2) in vec3 aPos;
out vec3 ourColor; // output a color to the fragment shader

uniform float movex;
uniform float movey;

void main()
{

    gl_Position = vec4(aPos.x + movex  , aPos.y +movey   , aPos.z, 1.0);
    ourColor = aColor; // set ourColor to the input color we got from the vertex data






}       