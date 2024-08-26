#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include"engine_work.h"
//#include"penis.hpp"

//#include"CUMERA.cpp"

class camera {
public:
    bool firstmovmouse = true; bool firstinitclass_mcallback = false;
    short int typecam_;
    int w_ = 1600;
    int h_ = 960;

    float lastX_ = w_ / 2;
    float lastY_ = h_ / 2;

    float radik_;
    float yaw_;
    float pitch_;
    
    void take_obj();
  
    void _mouse_callback_(GLFWwindow* window, double &xpos, double &ypos, CALL_PROC* call_proc);
   
    void cameralogic_fly(CALL_PROC* call_proc);
};

//void camera::mouse_callback(GLFWwindow* window, double xpos, double ypos);

 // void mouse_callback (GLFWwindow* window, double xpos, double ypos);
	


	//*/

#endif
