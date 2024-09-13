
//#define end <<std::endl
//#define ret return

#include"OBJ.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>

#define end <<std::endl
#define ret return
//-------------------
obj::obj()
{

}
obj::~obj()
{

}
//-----------------
void obj::box_van(texture* tex)
{
    std::string mdl = "model";
      
       

           glm::mat4 model = glm::mat4(1.0f);
           model = glm::translate(model, glm::vec3(-0.3f, -0.3f, -2.8f )   );
           angle += 0.539;
           model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

          
           glUniformMatrix4fv(glGetUniformLocation(id, "model"), 1, GL_FALSE, &model[0][0]);
           glUniform1i(glGetUniformLocation(id, "load_tex"), tex->texture1);

      

           glDrawArrays(GL_TRIANGLES, 0, 36);
           model = glm::translate(model, glm::vec3(-0.3f, -0.3f, 2.8f));
                     
	ret;
}
void obj::box_billy(texture* tex)
{
   // std::string mdl = "model";
   


    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.3f, 0.3f, -2.8f));
    angle += 0.539;
    model = glm::rotate(model, glm::radians(-angle), glm::vec3(3.0f, 0.8f, 0.5f));


    glUniformMatrix4fv(glGetUniformLocation(id, "model"), 1, GL_FALSE, &model[0][0]);
    glUniform1i(glGetUniformLocation(id, "load_tex"), tex->billy);

    glDrawArrays(GL_TRIANGLES, 0, 18);//+1
     model = glm::translate(model, glm::vec3(-0.3f, -0.3f, 2.8f));
    

    ret;
}