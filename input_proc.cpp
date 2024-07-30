
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

	void key_vertex_move(GLFWwindow * window)
	{
		
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{




			shader.setfloat("movex", fl += 0.01);
			std::cout << fl;
		}


		shader.setfloat("movey", 0.1f);
	}







private:
	check_file_text shader;
	float fl = 0.1;
};