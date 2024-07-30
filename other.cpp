

#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>

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
