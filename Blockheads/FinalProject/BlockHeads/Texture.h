//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#include <string>
#include <GLAD/glad.h>

class Texture
{
public:
	Texture(const char* fileName, int param = GL_LINEAR);
	void Bind();
	~Texture();
private:
	GLuint texture;
};
