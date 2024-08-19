
#ifndef SHADER_1
#define SHADER_1
#endif

////
#include <glad/glad.h>
#include<GLFW/glfw3.h>

///////next inc
#include<iostream>
#include"penis.hpp"





class  input {
public:
	float radians = 15.0f;
	float radians_tex = 0.0f;
	float cumera_speed = 1.2f * (float)glfwGetTime();


	void key_check_esc(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			std::cout << "close window" << std::endl;
			glfwSetWindowShouldClose(window, true); ;
		}
	}

	void key_polygon_off_on(GLFWwindow*window)
	{
		if (glfwGetKey(window, GLFW_KEY_P) ==GLFW_PRESS) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			std::cout << "POLYGON_MODE_TRUE" << std::endl;
		}
		
		if (glfwGetKey(window, GLFW_KEY_O)==GLFW_PRESS) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			std::cout << "POLYGON_MODE_FALSE" << std::endl;
		}
	
	}

	
	

	







private:
	
	float fl = 0.1;
};