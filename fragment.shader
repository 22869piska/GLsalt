

#version 330 core
out vec4 FragColor;


  in vec3 ourColor;
//in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  






void main()
{
    
    FragColor = vec4(ourColor,1.0);
} 