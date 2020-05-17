//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#pragma once
#include <GLAD/glad.h>
#include "glm/glm.hpp"

struct Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord = glm::vec2(0, 0), const glm::vec3& normal = glm::vec3())
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

enum MeshBufferPositions
{
	POSITION_VB,
	TEXCOORD_VB,
	NORMAL_VB,
	INDEX_VB,

	NUM_BUFFERS
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, bool generateNormal = true);
	~Mesh();
	void Draw();

private:
	GLuint VAO;
	GLuint VBO[NUM_BUFFERS];
	unsigned int drawCount;
	glm::vec3 calcNormal(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
};

