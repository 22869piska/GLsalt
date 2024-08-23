#include <glad/glad.h>
#include<GLFW/glfw3.h>

///////next inc
#include<iostream>


class debug {
public:
	void _MAXVERTEXATTRIBS_check()
	{

		int nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	}
	void camera_pos(float x,float y,float z)
	{
		std::cout << "(x=" << x<<")";
		std::cout << "(y=" << y << ")";
		std::cout << "(z=" <<z << ")";
		std::cout << std::endl;
	}


private:
	void error_and_close(GLFWwindow* window)
	{
		glfwSetWindowShouldClose(window,true);
	}

};