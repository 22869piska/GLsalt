
#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform vec4 scolor;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
   
  //  FragColor = texture(texture1, TexCoord);
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord)*scolor, 0.4);

}