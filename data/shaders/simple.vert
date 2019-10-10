#version 330 core

uniform mat4 projection_matrix;
uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform vec3 model_center;

in vec3 vtx_position;

out vec3 v_position;
out vec3 center;

void main()
{
    v_position = (view_matrix * model_matrix * vec4(vtx_position, 1.)).xyz;    
    center = (view_matrix * model_matrix * vec4(model_center, 1.)).xyz;	
    gl_Position = projection_matrix * vec4(v_position, 1.);
}
