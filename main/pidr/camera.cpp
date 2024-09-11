
#include"camera.h"
//#define publ
//#include "main/public.h"
#define end <<std::endl
#define ret return



bool camera::test()
{
	std::cout << "test_true" end;
	ret true;
}
//--------------------------------------------
void camera::cam_fly(unsigned int id)
{
	//
	//glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model,glm::radians(-50.f),glm::vec3(0.0f,0.0f,0.0f)   );
	//
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.1f, 0.3f, 0.1f));
	//
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(50.0f), 1600.f / 920.0f, 0.1f, 300.0f);

	//------------------------>
	/*int model_loc = glGetUniformLocation(id, "model");
	//glUniformMatrix4fv(model_loc,1,GL_FALSE,glm::value_ptr(model)  );
	//
	int projection_loc = glGetUniformLocation(id, "projection");
	glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection));
	//
	*/
	int view_loc = glGetUniformLocation(id, "view");
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));

	//------------------------>
	











}