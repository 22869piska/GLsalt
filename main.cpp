






////
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLFW/stb_image.h>

//#include<stb_image.h>
///////next inc
#include<iostream>
#include <string> 
#include <fstream> 
//

/// /// user inc
//#include "input_proc.hpp"
#include "other.hpp"
#include"engine_proc.h"
//#include"stb_image.h"
using namespace std;
////////////////////////

void resize_window(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	cout << width << "_" << height << endl;
}

int w = 1600;
 int h = 960;

int main(void)
{

	
	/////////////////////////////class-init--------------------------------------------------------------------------
	input input_;
	debug debug_;
	other_obj other_obj_;
	//draw draw_;
	//logic logic_;
	CALL_PROC call_proc;
	

	////////////////////////////class
	//govno_.start_();
	if (glfwInit() != true) { return-1111; };

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(w, h, "SOLEVOY228", 0, 0); if (window == 0) { return-1111; }
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "glad v govne" <<endl;
		return -11111;
	}
	
	check_file_text shader("vertex.shader","fragment.shader");/////////////////////////////////shader compile;

	glViewport(0, 0, w, h);//render porno gde//

	glfwSetFramebufferSizeCallback(window, resize_window);
	//gl_gr
	////////////////////////////////shdergenbin///////////////////////////////////////////



 //vao_crft_//->VAO
 unsigned int VBO, VAO, EBO;
 glGenVertexArrays(1, &VAO);
 glGenBuffers(1, &VBO);
 glGenBuffers(1, &EBO);

 glBindVertexArray(VAO);

 glBindBuffer(GL_ARRAY_BUFFER, VBO);
 glBufferData(GL_ARRAY_BUFFER, sizeof(_3angle_), _3angle_, GL_STATIC_DRAW);

 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
 glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

 // position attribute
 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
 glEnableVertexAttribArray(0);
 
 glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
 glEnableVertexAttribArray(1);
 
 //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
 //glEnableVertexAttribArray(2);

 glBindBuffer(GL_ARRAY_BUFFER, 0);
 glBindVertexArray(0);


 /////end////->next->///->texture_param//////////////////////////////////////////////////////////////////////////////////
 ;
 

 unsigned int texture1, texture2;
 // texture 1

 glGenTextures(1, &texture1);
 glBindTexture(GL_TEXTURE_2D, texture1);

 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

 int width, height, nrChannels;
 stbi_set_flip_vertically_on_load(true);

 unsigned char* data = stbi_load("res/artvan1080x1080.jpg", &width, &height, &nrChannels, 0);
 if (data)
 {
	 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	 glGenerateMipmap(GL_TEXTURE_2D);
 }

 stbi_image_free(data);
 // texture 2
 // ---------
 glGenTextures(1, &texture2);
 glBindTexture(GL_TEXTURE_2D, texture2);

 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

 data = stbi_load("res/billy.png", &width, &height, &nrChannels, 0);
 if (data)
 {
	 //GL_RGBA
	 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	 glGenerateMipmap(GL_TEXTURE_2D);
 }

 stbi_image_free(data);

 shader.use();

 glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);

 glUniform1i(glGetUniformLocation(shader.ID, "texture2"), 1);

 //////////////////////////////GLM::MATH////////////////////////////////////////////////////////////////////////////////
 cout << "GLM::MATH" << endl;

 //////////////////////////////////////////////////DEBUG//////////////////////////////////////////INFO/////////////////////////////
	 cout << "[----\t\tstart debug info\t\t\t----]" << endl;
 debug_._MAXVERTEXATTRIBS_check();
 
 cout << "[----\t\tend debug info\t\t\t----]" << endl;
 //--
 
 // --
 ///////////////////////////////////////////////////////////END//////////////////////////////////////////////////////////////////
 GLFW_OPENGL_DEBUG_CONTEXT;
glEnable(GL_DEPTH_TEST);
glEnable(GL_DEPTH);

double cpos1, cpos2;
glfwGetCursorPos(window, &cpos1, &cpos2);
cout << "1psrsr==>" << cpos1 << "2pscrsr==>" << cpos2 << endl;
//kallovvayuamassa//

//;/ int skok = 1;
//glm::vec3* boxpos = new glm::vec3[skok];



//end
 cout << "-----------------whilestart-----------------" << endl;
////while next->////--------------------------------------------------------while________-----___-__--------____-_-_--------_____---
	while (!glfwWindowShouldClose(window))
	{
		//masiv
		
		//call_proc.box_arr(&boxpos,&skok);
		//call_proc.box_setpos(&boxpos,&skok);



		///end masiv
		
		///next->input_
		input_.key_check_esc(window);//exit
		input_.key_polygon_off_on(window);
		shader.set_RGB(window);

		
		
		/////////render cmd->

		glBindTexture(GL_TEXTURE_2D, texture1);

		call_proc.draw_color(other_obj_.x, other_obj_.y, other_obj_.z);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glBindVertexArray(VAO);

	
	
		// create
		shader.use();

	

		
		//
		

		call_proc.matlogc(shader.ID,w,h,window);
		



		//call_proc.draw_3angl();
		//call_proc.draw_elements();

	
		//////////////////////
		glfwSwapInterval(60);
		glfwSwapBuffers(window);
		glfwPollEvents();

		///////////////////////
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwDestroyWindow(window);
	glfwTerminate();

	call_proc.delete_array();
	//delete[] boxpos;
}

