#version 400 core

in vec2 oTexCoord;
in vec3 oPosition;
in vec3 oNormal;

out vec4 color;

uniform vec3 lightColor;
uniform vec3 lightPos; 
uniform vec3 viewPos;

uniform sampler2D ourTexture;

void main()
{
	float ambientStrength = 0.1f;
	float specularStrength = 1.0f;

	// diffuse

	vec3 norm = normalize(oNormal);
    vec3 lightDir = normalize(lightPos - oPosition);  

	float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

	// specular

	vec3 viewDir = normalize(viewPos - oPosition);
    vec3 reflectDir = reflect(-lightDir, norm);  

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    vec3 specular = specularStrength * spec * lightColor;  


    color = vec4((ambientStrength + diffuse + specular), 0.0f) * texture(ourTexture, oTexCoord);



} 