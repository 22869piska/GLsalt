



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
	unsigned int arr_pos;
	string prj = "projection"; string modl = "model";

   public:

	   float cumera_speed = static_cast<float>(0.08f);

	   int skok = 1;
	   glm::vec3* boxpos = new glm::vec3[skok];

	   glm::vec3 setposbox; //cameraPos;// = glm::vec3(0.1, 0.2f, 0.3f);

// fvec1, fvec2, fvec3;

	   float  fvec1=5.1f;
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
	//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void box_setpos2(glm::vec3* boxpos[], int skok,glm::vec3 setpos,unsigned int array_pos)
	{
		//setposbox = setpos;
	//	boxpos[skok] = setpos;


	}//end proc//
	
	void box_setpos( unsigned int array_pos, glm::vec3 setpos)
	{
		//setposbox = setpos;
		skok += 1;
		boxpos[skok] =setpos;


	}//end proc//
	void matlogc(unsigned int ID, int w, int h,GLFWwindow* window)
	{ 
		boxpos[0] = glm::vec3(0.1, 0.2f, 1.3f);;	boxpos[1] = glm::vec3(0.1, 0.2f, 0.3f); ;
		
		//cumera//////////
			///cumera///////////////////////////////////////////////////////////
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
		/////////////////////end.cum////////////////////////////////
		//////
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(50.0f), (float)w / (float)h, 0.1f, 100.0f);
		//->
		//start if
	// cumera_speed = static_cast<float>(0.08f );
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
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) *cumera_speed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cumera_speed;
		}
		//qe//
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		{
			this->fvec1 += 0.3f;
			



		}
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		{

			//setposbox = cameraPos;
			setposbox = (vec1,vec2,vec3);
			box_setpos(arr_pos,setposbox);
			
		}
	
		pisda:
		//end if//
	//set_arr//
	
	
		//box_setpos(  setposbox, arr_pos);


		//end arr//
         ///////////////////////////end//init...//////
		for (unsigned int i = 0; i < skok; i++)//start for
		{
			cout <<"i=" << i;
			

			//model = glm::translate(model, boxpos[1]);
			model = glm::translate(model, boxpos[i]);
		
			


			glUniformMatrix4fv(glGetUniformLocation(ID, modl.c_str()), 1, GL_FALSE, &model[0][0]);
		
			glDrawArrays(GL_TRIANGLES, 0, 36);



			unsigned int modelLoc = glGetUniformLocation(ID, "model");
			unsigned int viewLoc = glGetUniformLocation(ID, "view");

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

			glUniformMatrix4fv(glGetUniformLocation(ID, prj.c_str()), 1, GL_FALSE, &projection[0][0]);
		}//end for

	}//end proc mathlog//
		
	void delete_array()
	{
		delete[] boxpos;	
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