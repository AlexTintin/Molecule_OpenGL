#version 330 core

 
uniform float model_radius;
uniform mat4 projection_matrix;
uniform vec3 model_color;

in vec3 center;
in vec3 v_position;

out vec4 out_color;

void main(void) {

	float a = dot(v_position,v_position);
	float b = -2*dot(v_position,center);
	float c = dot(center,center)- model_radius*model_radius;
	float delta = b*b-4*a*c;
	float alpha1,alpha2;
	vec3 pos;
	if (delta >= 0)
	{
		alpha1 = (-b+sqrt(delta))/(2*a);
		alpha2 = (-b-sqrt(delta))/(2*a);
	}
	else
	{
		discard;
	}
	if (alpha1 <= alpha2 && alpha1 >= 0)
	{
		pos = alpha1 * v_position;
	}
	else if (alpha2 < alpha1 && alpha2 >= 0)
	{
		pos = alpha2 * v_position;
	}
	else
	{
		discard;
	}
	
    vec3 n = normalize(pos-center);   	

    vec3 viewDir = -normalize(pos);
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));
    vec3 lightColor = vec3(1.0);
    
    vec3 ka = 0.2*model_color;
    vec3 kd = model_color;
    vec3 ks = vec3(0.8);
    float shininess = 50.0;
    
    vec3 diffuse = kd * max(dot(n, lightDir), 0.0);
    
    vec3 r = normalize(reflect(lightDir, n));
    vec3 specular = ks * pow(max(dot(lightDir, n), 0.0), shininess);

    vec3 outColor = ka + lightColor * (diffuse + specular);


vec4 P_projected = projection_matrix * vec4(pos, 1.);
float ndcDepth = P_projected.z/P_projected.w;
gl_FragDepth = ((gl_DepthRange.diff * ndcDepth)+ gl_DepthRange.near + gl_DepthRange.far) / 2.0;   

   	
out_color = vec4(outColor,1.0);

}


