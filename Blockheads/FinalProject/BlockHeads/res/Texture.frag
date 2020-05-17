#version 330 core
in vec2 TexCoord;
in vec3 Normal;  
in vec3 FragPos;  

// Texture samplers
uniform sampler2D ourTexture;
uniform vec3 camera;
uniform vec3 lightDirU;

void main()
{
	vec4 texel = texture(ourTexture, TexCoord);
	if(texel.a < 0.5)
		discard;

	// ambient
    float ambientStrength = 0.7;
    vec3 ambient = vec3(0.8f, 0.8f, 0.8f) * texture(ourTexture, TexCoord).rgb;
  	
	vec3 result = ambient;
	gl_FragColor = vec4(result, 1.0);
}
