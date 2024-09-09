#define ret return
#define STB_IMAGE_IMPLEMENTATION
#include <GLFW/stb_image.h>
#include"texture.h"
#define end <<std::endl
texture::~texture()
{
   
}
void texture::texture_bind()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    //
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, t_wall);

}

void texture::ALL_TEXTURE()
{
    texture_1( );
    texture_billy_stronk( );
    texture_wall();
}

//texture->

void texture::texture_1()
{
   // texture::texture1;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
   //
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("res/artvan1080x1080.jpg", &width, &height, &nrChannels, 0);
    stbi_set_flip_vertically_on_load(false);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout <<std::endl<< "LOAD_TEXTURE_ARTVAN"<<std::endl;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
  glUniform1i(glGetUniformLocation( id, "texture1"), 0);
    stbi_image_free(data);

}
void texture::texture_billy_stronk()
{

   // texture2;
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("res/billy.png", &width, &height, &nrChannels, 0);
    stbi_set_flip_vertically_on_load(false);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout<< "LOAD_TEXTURE_BILLY|STRONK" << std::endl;
    }
    else
    {
        std::cout << "FAIL______________________ LOAD_TEXTURE_BILLY|STRONK" << std::endl;
    }
    glUniform1i(glGetUniformLocation(id, "texture2"), 1);
    stbi_image_free(data);
}
void texture::texture_wall()
{
    // texture::texture1;
    glGenTextures(1, &t_wall);
    glBindTexture(GL_TEXTURE_2D, t_wall);
    //
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("res/wall.jpg", &width, &height, &nrChannels, 0);
    stbi_set_flip_vertically_on_load(false);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout  << "LOAD_TEXTURE_WALL" end;
    }
    else
    {
        std::cout << "Failed to load wall" << std::endl;
    }
    glUniform1i(glGetUniformLocation(id, "t_wall"), 2);
    stbi_image_free(data);

}