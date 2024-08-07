

#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>


/*float _3angle_[] = {

	// positions         // colors
	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,    // bottom right
   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,    // bottom left
	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, //top
	..

float texCoords[] = {
	0.0f, 0.0f,  // lower-left corner
	1.0f, 0.0f,  // lower-right corner
	0.5f, 1.0f   // top-center corner
};
..
};*/

float _3angle_[] = {
	// positions          // colors           // texture coords
	 // positions          // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
};



float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };////////////////BORDERCOLOR
unsigned int indices[] = {  // start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};
class other_obj {

public:
	other_obj(){}
	~other_obj(){}

	//0.1f, 0.2f, 0.3f
	float x = 0.1f;
	float y = 0.2f;
	float z = 0.3f;

	void key_color_change(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
		{
			 x = 0.1f;
			 y = 0.2f;
			 z = 0.3f;
		}
	}
private:

};
