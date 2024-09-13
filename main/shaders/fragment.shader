
#version 330 core
//out vec4 FragColor;
out vec4 testcolor;
  
//
in vec3 ourColor;
in vec2 TexCoord;


uniform bool set;
uniform vec3 color;
uniform sampler2D ourTexture;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D t_wall;

uniform sampler2D load_tex;
 

void main()
{
   //testcolor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord)*vec4(color,0.9f), 0.5f);
   

   testcolor= texture(load_tex, TexCoord);//*vec4(color,1.0f);

}