#version 400 core
  
layout(location = 0) in vec3 vertexPosition_modelspace;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec2 oTexCoord;
out vec3 oNormal;
out vec3 oPosition;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
  
void main(){
  oTexCoord = texCoord;
  gl_Position =  Projection * View * Model * vec4(vertexPosition_modelspace,1);

  oPosition = (Model * vec4(vertexPosition_modelspace, 1.0)).xyz;
  oNormal = mat3(transpose(inverse(Model))) * normal;
}