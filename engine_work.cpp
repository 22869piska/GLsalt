



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

//  const static int skok = 5;
//  static glm::vec3 boxpos[skok] =
//{
	//  glm::vec3(0.0f,0.0f,0.0f),
//	  glm::vec3(1.0f,1.0f,1.0f),
  //  glm::vec3(0.0f,1.0f,0.0f),
//	  glm::vec3(0.0f,2.2f,0.0f),
//	 glm::vec3(0.0f,0.0f,1.0f)
//};


class logic
{
	
	float lastX=820;
    float lastY=600;

	float radik  ;
	float yaw;
	float pitch;
	unsigned int arr_pos;
	
	string prj = "projection"; string modl = "model";

   public:
	   logic() 
	   {
		   boxpos[0] = glm::vec3(0.0f, 0.0f, 0.0f); 
		   boxpos[1] = glm::vec3(1.0f, 0.0f, 0.0f);
		 //  boxpos[2] = glm::vec3(2.0f, 0.0f, 0.0f);
	   };
	  ~logic()
	   {
		  delete[]boxpos;
	   };

	   float cumera_speed = static_cast<float>(0.08f);
	   int skok = 2;
	   glm::vec3* boxpos = new glm::vec3[skok] ;
	   glm::vec3 setposbox; //cameraPos;// = glm::vec3(0.1, 0.2f, 0.3f);

// fvec1, fvec2, fvec3;

	   float  fvec1=0.1f;
	   float  fvec2=0.1f;
	   float  fvec3=0.1f;
	   
	glm::vec3   vec1 = glm::vec3(fvec1, 0.0f, 0.0f); //x
	glm::vec3   vec2 = glm::vec3(0.0f, fvec2, 0.0f);//y
	glm::vec3   vec3 = glm::vec3(0.0f, 0.0f, fvec3);//z

/////////init.//
	int pidr;
	//cum
	// camera
	glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -3.0f);
	glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 direction;
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
//	glfwSetCursorPosCallback(window, mouse_callback);

	void box_setpos2(glm::vec3* boxpos[], int skok,glm::vec3 setpos,unsigned int array_pos)
	{
	
	}//end proc//
	
	void box_setpos( unsigned int array_pos, glm::vec3 setpos)
	{
		boxpos[skok] = setpos;

	}//end proc//
	void matlogc(unsigned int ID, int w, int h,GLFWwindow* window,float frominputset)
	{ 
		cameraPos.y = frominputset;

			///cumera///////////////////////////////////////////////////////////
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
		/////////////////////end.cum////////////////////////////////
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(50.0f), (float)w / (float)h, 0.1f, 148.8f);
		//->
	

		//------------->next
		_ifs_(window);
		
         ///////////////////////////end//init...//////
		for (unsigned int i = 0; i < skok; i++)//start for
		{
			
			model = glm::translate(model, boxpos[i] );
			

	
		
			//parasha//
			pozor( ID, model,  view, projection);//хуйня//
			model = glm::translate(model, -boxpos[i]);//шаг назад к 0,0,0 вектору //glm::vec3(0.0f,0.0f,0.0f)//
		}//end for
		
	}//end proc mathlog//
   
	void move_box(int arr_pos)
	{
		boxpos[arr_pos] += glm::vec3(fvec1,fvec2 - 0.1,fvec3 - 0.1);
	}
	void _ifs_(GLFWwindow* window)
	{
		//start if

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			cameraPos += cumera_speed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			cameraPos -= cumera_speed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cumera_speed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cumera_speed;
		}
		//qe//////////////////////////////////////////////////////QE//////////////////
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		{
			move_box(1);
			//boxpos[0] = glm::vec3(fvec1,fvec2,fvec3);

		}
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		{
			skok += 1;
			box_setpos(0, cameraPos);
		}
	}
	
	void delete_array()
	{
		delete[] boxpos;
	}
private:

	void pozor(unsigned int ID, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, modl.c_str()), 1, GL_FALSE, &model[0][0]);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		unsigned int modelLoc = glGetUniformLocation(ID, "model");
		unsigned int viewLoc = glGetUniformLocation(ID, "view");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

		glUniformMatrix4fv(glGetUniformLocation(ID, prj.c_str()), 1, GL_FALSE, &projection[0][0]);
	}


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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //| GL_DEPTH_BUFFER_BIT
	}
	void draw_3angl()
	{
		glDrawArrays(GL_TRIANGLES, 0, 36);
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