#pragma once
#ifndef publ
#define publ
//
using namespace std;
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include<string>
//

float _3angle_[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};
unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
};

float texCoords[] = {
    0.0f, 0.0f,  // 
    1.0f, 0.0f,  // 
    0.5f, 1.0f   //
};
//--------------------------------------------------------------------------------------------------------------------------
string unif_color = "color";
GLfloat color_x = 0; GLfloat color_y = 0; GLfloat color_z = 0;
//
GLuint VAO; GLuint VBO; GLuint EBO;
GLFWgammaramp gamma_ramp;
GLFWwindow* window = 0;
GLFWmonitor* monitor = 0;
//--------------------------------------------------------------------------------------------------------------------------







#endif 
