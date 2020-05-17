//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#pragma once
#include "../Mesh.h"

static Mesh* Box() {
	Vertex vertices[] = {
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 1.0f / 3)),
		Vertex(glm::vec3(-1, 1, -1),  glm::vec2(1, 2.0f / 3 - 0.001f)),
		Vertex(glm::vec3(1, 1, -1),   glm::vec2(0.75, 2.0f / 3 - 0.001f)),
		Vertex(glm::vec3(1, -1, -1),  glm::vec2(0.75, 1.0f / 3)),

		Vertex(glm::vec3(-1, -1, 1),  glm::vec2(0.25, 1.0f / 3)),
		Vertex(glm::vec3(-1, 1, 1),   glm::vec2(0.25, 2.0f / 3 - 0.001f)),
		Vertex(glm::vec3(1, 1, 1),    glm::vec2(0.50, 2.0f / 3 - 0.001f)),
		Vertex(glm::vec3(1, -1, 1),   glm::vec2(0.50, 1.0f / 3)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0.25, 0)),
		Vertex(glm::vec3(-1, -1, 1),  glm::vec2(0.50, 0)),
		Vertex(glm::vec3(1, -1, 1),   glm::vec2(0.50, 1.0f/3)),
		Vertex(glm::vec3(1, -1, -1),  glm::vec2(0.25, 1.0f/3)),

		Vertex(glm::vec3(-1, 1, -1),  glm::vec2(0.25, 1)),
		Vertex(glm::vec3(-1, 1, 1),   glm::vec2(0.25, 2.0f / 3)),
		Vertex(glm::vec3(1, 1, 1),    glm::vec2(0.50, 2.0f / 3)),
		Vertex(glm::vec3(1, 1, -1),   glm::vec2(0.50, 1)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0, 1.0f / 3)),
		Vertex(glm::vec3(-1, -1, 1),  glm::vec2(0.25, 1.0f / 3)),
		Vertex(glm::vec3(-1, 1, 1),   glm::vec2(0.25, 2.0f / 3 - 0.001f)),
		Vertex(glm::vec3(-1, 1, -1),  glm::vec2(0, 2.0f / 3 - 0.001f)),

		Vertex(glm::vec3(1, -1, -1),  glm::vec2(0.75, 1.0f / 3)),
		Vertex(glm::vec3(1, -1, 1),   glm::vec2(0.50, 1.0f / 3)),
		Vertex(glm::vec3(1, 1, 1),    glm::vec2(0.50, 2.0f / 3 - 0.001f)),
		Vertex(glm::vec3(1, 1, -1),   glm::vec2(0.75, 2.0f / 3 - 0.001f)),
	};

	unsigned int indices[] = {
		0, 1, 2,
		0, 2, 3,

		6, 5, 4,
		7, 6, 4,

		10, 9, 8,
		11, 10, 8,

		12, 13, 14,
		12, 14, 15,

		16, 17, 18,
		16, 18, 19,

		22, 21, 20,
		23, 22, 20,
	};

	return new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}
