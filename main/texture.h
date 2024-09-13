#ifndef PIDORSOLINIO
#define PIDORSOLINIO
//
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

class texture
{
public:
	~texture();

	//--
	 void swap_tex();
	//
	 void texture_bind();
	 void ALL_TEXTURE();
	//
	 void texture_1();
	 void texture_billy_stronk();
	 void texture_wall();
	//
	
	


	 unsigned int id;
private:
public:
	unsigned int texture1; unsigned int billy; unsigned int t_wall;
	
};














#endif 

