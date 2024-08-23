






////
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLFW/stb_image.h>

//#include<stb_image.h>
///////next inc
#include<iostream>
#include <string> 
#include <fstream> 
#include<ctime>
//

/// /// user inc
//#include "input_proc.hpp"
#include "other.hpp"
#include"engine_proc.h"
//#include"stb_image.h"
using namespace std;
////////////////////////


bool firstmovmouse = true;
int w = 1600;
int h = 960;

float lastX = w/2;
float lastY = h/2;

float radik;
float yaw;
float pitch;

input input_;
debug debug_;
other_obj other_obj_;
//draw draw_;
//logic logic_;
CALL_PROC call_proc;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void resize_window(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	cout << width << "_" << height << endl;
}


int main(void)
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	
	/////////////////////////////class-init--------------------------------------------------------------------------
	
	

	////////////////////////////class
	//govno_.start_();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (glfwInit() != true) { return-1111; };
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
glfwSetInputMode(window,GLFW_CURSOR ,GLFW_CURSOR_DISABLED);


//end
 cout << "-----------------whilestart-----------------" << endl;
////while next->////--------------------------------------------------------while________-----___-__--------____-_-_--------_____---
	while (!glfwWindowShouldClose(window))
	{
		
		///next->input_
		glfwSetCursorPosCallback(window, mouse_callback);
		
		input_.mov_updown(window);
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

		call_proc.matlogc(shader.ID,w,h,window,input_.cameraPosY);
		
		//debug_.camera_pos(call_proc.cameraPos.x, call_proc.cameraPos.y, call_proc.cameraPos.z);
	
		//////////////////////
		glfwSwapInterval(60);
		glfwSwapBuffers(window);
		//glfwWaitEvents();
		glfwPollEvents();

		///////////////////////
	}//end while

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwDestroyWindow(window);
	glfwTerminate();

	//call_proc.delete_array();
	////delete[] boxpos;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstmovmouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstmovmouse = false;
	}
	float xoffset = xpos -lastX;//0
	float yoffset = lastY -ypos;//0
	lastX = xpos;
	lastY = ypos;

	 float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;


	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	
	 call_proc.cameraFront = glm::normalize(direction);
	 call_proc.direction = direction;
	/*cout << "direction.x=" << call_proc.direction.x;
	cout << "direction.y=" << call_proc.direction.y;
	cout << "direction.z=" << call_proc.direction.z;
	std::cout << xoffset << "-" << yoffset << std::endl;
	*/

	

}