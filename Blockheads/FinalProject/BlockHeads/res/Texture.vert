#version 330
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 aNormal;

out vec2 TexCoord;
out vec3 FragPos;
out vec3 Normal;

uniform mat4 transform;

void main()
{
	vec4 pos = transform * vec4(position, 1.0f);
	FragPos = vec3(pos);
	Normal = aNormal;
	TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
	gl_Position = pos;
}