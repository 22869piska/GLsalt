






////
#include <glad/glad.h>
#include<GLFW/glfw3.h>

///////next inc
#include<iostream>
#include <string> 
#include <fstream> 

/// /// user inc
//#include "input_proc.hpp"
#include "other.hpp"
#include"engine_proc.h"

using namespace std;
////////////////////////





void resize_window(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	cout << width << "_" << height << endl;
}




int main(void)
{


	/////////////////////////////class-init--------------------------------------------------------------------------
	input input_;
	debug debug_;
	other_obj other_obj_;
	draw draw_;

	////////////////////////////class
	
	if (glfwInit() != true) { return-1111; };

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 840, "SOLEVOY228", 0, 0); if (window == 0) { return-1111; }
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "glad v govne" <<endl;
		return -11111;
	}
	
	check_file_text shader("vertex.shader","fragment.shader");/////////////////////////////////shader compile;

	glViewport(0, 0, 1280, 840);//render porno gde//

	glfwSetFramebufferSizeCallback(window, resize_window);
	//gl_gr
	////////////////////////////////shdergenbin///////////////////////////////////////////
	float _3angle_2[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bot right
	-0.5f, -0.5f, 0.0f,  // bot left
	-0.5f,  0.5f, 0.0f   // top left 
};

	float _3angle_[] = {

		// positions         // colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,    // bottom right
	   -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,    // bottom left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, //top
		



	// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
	 //  -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
	//	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
		
		
 
	};

unsigned int indices[] = {  // note that we start from 0!
	0, 1, 3,   // 1 triangle
	1, 2, 3    // 2 triangle
};


	unsigned int VBO;
 glGenBuffers(1, &VBO);

 glBindBuffer(GL_ARRAY_BUFFER, VBO);
 glBufferData(GL_ARRAY_BUFFER, sizeof(_3angle_), _3angle_, GL_STATIC_DRAW);// sizeof(float) * 9



 //->

 glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
 glEnableVertexAttribArray(1);

 //vao_crft_//->VAO

 unsigned int VAO;
 glGenVertexArrays(1, &VAO);

 glBindVertexArray(VAO);

 glBindBuffer(GL_ARRAY_BUFFER, VAO);
 glBufferData(GL_ARRAY_BUFFER,sizeof(_3angle_),_3angle_,GL_STATIC_DRAW);

//glad_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)) );
// glEnableVertexAttribArray(0);

   // position attribute
 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
 glEnableVertexAttribArray(0);
 // color attribute
 glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
 glEnableVertexAttribArray(1);
 //
 

 glBindBuffer(GL_ARRAY_BUFFER, 0);
 glBindVertexArray(0);


 //ebo_crft_//->EBO

 unsigned int EBO;
 glGenBuffers(1, &EBO);


     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
 


 //////////////////////////////////////////////////DEBUG//////////////////////////////////////////INFO/////////////////////////////

	 cout << "[----\t\tstart debug info\t\t\t----]" << endl;



 debug_._MAXVERTEXATTRIBS_check();
 //shader.check_errors();


 cout << "[----\t\tend debug info\t\t\t----]" << endl;
 ///////////////////////////////////////////////////////////END//////////////////////////////////////////////////////////////////
 float fl = 0.1;
 cout << "-----------------whilestart-----------------" << endl;
////while next->////--------------------------------------------------------while________-----___-__--------____-_-_--------_____---
	while (!glfwWindowShouldClose(window))
	{
	
		///next->input_
		input_.key_check_esc(window);
		input_.key_polygon_off_on(window);

		input_.key_vertex_move(window);
	

		/////////render cmd->
		glClearColor(other_obj_.x, other_obj_.y, other_obj_.z, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		
	
		shader.use();
	
		

		glBindVertexArray(VAO);

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		

		


		//////////////////////
		glfwSwapInterval(60);
		glfwSwapBuffers(window);
		glfwPollEvents();

		///////////////////////
	}




	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	//glDeleteProgram(shaderprogram);




	glfwDestroyWindow(window);
	glfwTerminate();
}