
////
#include <glad/glad.h>
#include<GLFW/glfw3.h>
//#include<GLFW/stb_image.h>

//#include<stb_image.h>
///////next inc
#include<iostream>
#include <string> 
#include <fstream> 
#include<ctime>


/// user inc next-----------------------------------------------------
#include"public.h"
#include"shader.h"
#include"texture.h"
#include"headers.h"
//define--------------------------------------------------------------
using namespace std;
#define ret return
#define end <<std::endl
/// 

int W_ = 1600; int H_ = 920;

//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
void resize(GLFWwindow* window, int width, int height);
void windowinit__();
void _in(GLFWwindow* window,check_file_text* shader);
void _gl_compile();
void _delete(); void __TEST__(check_file_text * shader);
//->--------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------
int main()
{
#ifdef _DEBUG
    cout << "DEBUG_MODE" end;
    bool a = _test_pidr(true);
#else
    std::cout << "RELEASE_\n";
#endif 
	windowinit__();
    glfwSetFramebufferSizeCallback(window, resize);
   //
    check_file_text* shader=new check_file_text("main/shaders/vertex.shader", "main/shaders/fragment.shader");  _gl_compile();
    texture* tex = new texture; camera* cam = new camera; obj* obj_ = new obj;
    
    cout end <<"A=" << a end;
   
    //-------------------------------
    tex->id = shader->GET_id(); obj_->id = shader->ID;
    shader->use();
   tex->ALL_TEXTURE();
   
   
   //->
    glEnable(GL_DEPTH_TEST);
    
   //--------------------------------
    __TEST__(shader);
    while (!glfwWindowShouldClose(window))
    {//pidrput->
        
        _in(window,shader);
        //render->
        shader->use();
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       

        cam->cam_fly(shader->ID);

        glBindVertexArray(VAO);
        tex->texture_bind();

     
        //-->
        obj_->box_van(tex); obj_->box_billy(tex);
         

        ///end//
        glfwSwapInterval(60);
        glfwSwapBuffers(window);
        glfwPollEvents();

    }//endwhile//
    //
   // delete shader;
    //delete tex;// delete cam;
    _delete();
    ///
    glfwTerminate();
   
	ret 0;
}





void _delete()
{
   
}
void _in(GLFWwindow* window, check_file_text* shader)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
    {
        glfwSetWindowShouldClose(window, true);//exit
    }
    //->
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS)
    {
        color_x += 0.01;
        glUniform3f(glGetUniformLocation(shader->ID, unif_color.c_str()), color_x, 0, 0);
       
    }
    if (glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS)
    {
        color_y += 0.01;
        glUniform3f(glGetUniformLocation(shader->ID, unif_color.c_str()), 0, color_y, 0);
        
    }
    if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS)
    {
        color_z += 0.01;
        glUniform3f(glGetUniformLocation(shader->ID, unif_color.c_str()), 0, 0, color_z);
    }
   //->
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      //  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
       // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

}
void windowinit__()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //
    window = glfwCreateWindow(W_,H_, "SALT_BOY", NULL, NULL);
 if (window == 0) { glfwTerminate();  cout << "NETY_WINDOW_BLYA"; }
#ifdef _DEBUG
    cout <<"WINDOW=="<< window end;
#endif
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
#ifdef _DEBUG
      cout << " GLAD_V_GOVNE_POLNOM" << std::endl;
 #endif
  }
  //
   //monitor = glfwGetPrimaryMonitor();
  // glfwGetMonitorWorkarea(monitor, NULL, NULL, &W_, &H_);
  glViewport(0, 0, W_, H_);
 // glfwSetWindowSize(window,W_,H_);

#ifdef _DEBUG
  cout << W_<<"-" << H_;
#endif

}
void resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void _gl_compile()
{
    //
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
  //
    glBindVertexArray(VAO);
    //
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_3angle_), _3angle_, GL_STATIC_DRAW);
    // 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    //

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //
    glBindVertexArray(0);
    //

}
void __TEST__(check_file_text* shader)
{
#ifdef _DEBUG

    camera::test();
    
       
 #endif
#ifndef _DEBUG
    cout << "netytestov" end;
#endif //_DEBUG
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(50.0f), 1600.f / 920.0f, 0.1f, 300.0f);
    int projection_loc = glGetUniformLocation(shader->ID, "projection");
    glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));
}