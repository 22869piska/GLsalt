



#include<iostream>


////
#include <glad/glad.h>
#include<GLFW/glfw3.h>

///////next inc
#include<iostream>
#include <string> 
#include <fstream> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


//#include "engine_proc.h"
using namespace std;


class logic
{
public:
	void matlogc(unsigned int ID)
	{
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, (float)glfwGetTime()*5, glm::vec3(0.0f, 0.0, 1.0f));//speed glfwgettime_if swap rotate->trans=rotate->obj
	
		unsigned int transformLoc = glGetUniformLocation(ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	}

private:
};

class draw {
public:
	
	draw()
	{
	}
	~draw() 
	{
	}

	
	void draw_color(float x, float y, float z)
	{
		glClearColor(x, y, z, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void draw_3angl()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	void draw_elements()
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	
	
private:

};

class CALL_PROC :public draw, public logic
{
public:


private:
};