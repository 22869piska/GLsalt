#pragma once
#ifndef pisdasos
#define pisdasos
#include <glad/glad.h>
#include<GLFW/glfw3.h>
//
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>


//-------------------------------------
 class camera
{
public:
	~camera();
	static bool test();
	 void cam_fly(unsigned int id);


private:
};











#endif