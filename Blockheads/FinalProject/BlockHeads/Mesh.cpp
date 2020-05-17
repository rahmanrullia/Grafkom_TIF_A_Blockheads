//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#include "Mesh.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <vector>

Mesh::Mesh(Vertex *vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, bool generateNormal)
{
	drawCount = numIndices;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;

	positions.reserve(numVertices);
	texCoords.reserve(numVertices);
	normals.reserve(numVertices);
	normals.resize(numVertices);

	for (int i = 0; i < numVertices; i++) {
		positions.push_back(vertices[i].pos);
		texCoords.push_back(vertices[i].texCoord);

		if (!generateNormal) {
			normals.push_back(vertices[i].normal);
		}
	}

	if (generateNormal) {
		for (int i = 0; i < numIndices; i++) {
			if (i % 3 == 0) {
				glm::vec3 normal = calcNormal(vertices[indices[i]].pos, vertices[indices[i + 1]].pos, vertices[indices[i + 2]].pos);
				normals[indices[i]] = normal;
				normals[indices[i + 1]] = normal;
				normals[indices[i + 2]] = normal;
			}
		}
	}

	glGenBuffers(NUM_BUFFERS, VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * numVertices, &positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * numVertices, &texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals[0]) * numVertices, &normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numIndices, &indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0); 
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
}

void Mesh::Draw()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

glm::vec3 Mesh::calcNormal(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3)
{
	glm::vec3 U = (p2 - p1);
	glm::vec3 V = (p3 - p1);

	glm::vec3 surfaceNormal;
	surfaceNormal.x = (U.y * V.z) - (U.z * V.y);
	surfaceNormal.y = (U.z * V.x) - (U.x * V.z);
	surfaceNormal.z = (U.x * V.y) - (U.y * V.x);

	return glm::normalize(surfaceNormal);
}
