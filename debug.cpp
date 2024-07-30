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




private:
	void error_and_close(GLFWwindow* window)
	{
		glfwSetWindowShouldClose(window,true);
	}

};