#pragma once
#ifndef OBJ_H
#define OBJ_H
//#include <glad/glad.h>
//#include<GLFW/glfw3.h>
//

//#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#define STOP_COMPL_H
#include"main/headers.h"
#include"main/texture.h"



class obj
{
public:
	obj();
	~obj();
	///--//////...////-------------------
	void box_van(texture* tex);
	void box_billy(texture* tex);

	//-----------------
	float angle = 20.0f; unsigned int id; float _testf_ = 0;
private:

	
};








#endif