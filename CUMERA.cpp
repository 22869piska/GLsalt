  #ifndef pidrila
  #define pidrila



#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>


#include"camera.hpp"
#include"engine_work.h"
//#include"main.cpp"
//#include"penis.hpp"
using namespace std;
using namespace glm;
//#include"penis.hpp"


//void  camera::mouse_callback(GLFWwindow* window, double xpos, double ypos);

class camera;

   ///*
bool firstmovmouse = true; bool firstinitclass_mcallback = false;
    short int typecam_;
    int w_ = 1600;
    int h_ = 960;

    float lastX_ = w_ / 2;
    float lastY_ = h_ / 2;

    float radik_;
    float yaw_;
    float pitch_;
  //  */
    void camera::take_obj()
    {
        
    }
    void camera::cameralogic_fly(CALL_PROC* call_proc)
    {
       
    }


    void  camera::_mouse_callback_(GLFWwindow* window, double &xposin, double &yposin, CALL_PROC* call_proc)
    {
   
		float xpos = static_cast<float>(xposin);
		float ypos = static_cast<float>(yposin);
		if (firstmovmouse)
		{
			lastX_ = xpos;
			lastY_ = ypos;
			firstmovmouse = false;
		}

		float xoffset = xpos - lastX_;
		float yoffset = lastY_ - ypos; // reversed since y-coordinates go from bottom to top
		lastX_ = xpos;
		lastY_ = ypos;

		float sensitivity = 0.1f; // change this value to your liking
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw_ += xoffset;
		pitch_ += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (pitch_ > 89.0f)
			pitch_ = 89.0f;
		if (pitch_ < -89.0f)
			pitch_ = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		front.y = sin(glm::radians(pitch_));
		front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
		call_proc->cameraFront = glm::normalize(front);
    }


//};


    #endif
