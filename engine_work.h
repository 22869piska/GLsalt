#pragma once
#ifndef pisos
#define pisos


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
	logic();
	~logic();
	float cumera_speed ;
	int skok;
	glm::vec3* boxpos = new glm::vec3[skok];
	glm::vec3 setposbox; //cameraPos;// = glm::vec3(0.1, 0.2f, 0.3f);
	float  fvec1 ;
	float  fvec2 ;
	float  fvec3 ;
	glm::vec3   vec1 ; //x
	glm::vec3   vec2 ;//y
	glm::vec3   vec3 ;//z
	int pidr;
	glm::vec3 cameraPos ;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp ;
	glm::vec3 cameraTarget ;
	glm::vec3 direction;
	void box_setpos2(glm::vec3* boxpos[], int skok, glm::vec3 setpos, unsigned int array_pos);
	void box_setpos(unsigned int array_pos, glm::vec3 setpos);
	void matlogc(unsigned int ID, int w, int h, GLFWwindow* window, float frominputset);
	void move_box(int arr_pos);
	void _ifs_(GLFWwindow* window);
	void delete_array();	
private:
	void pozor(unsigned int ID, glm::mat4 model, glm::mat4 view, glm::mat4 projection);
};

class draw {
public:
	draw();
	~draw();
	void draw_color(float x, float y, float z);
	void draw_3angl();
	void draw_elements();
private:
};

class CALL_PROC :public draw, public logic
{
public:
private:
};

#endif 

