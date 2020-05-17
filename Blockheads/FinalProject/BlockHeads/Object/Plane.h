//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#pragma once
#include "../Mesh.h"

static Mesh* Plane() {
	Vertex vertices[] = {
		Vertex(glm::vec3(-50, 0, -50.0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(50, 0, -50.0),  glm::vec2(50.0, 0.0)),
		Vertex(glm::vec3(50, 0, 50.0),   glm::vec2(50.0, 50.0)),
		Vertex(glm::vec3(-50, 0, 50.0),  glm::vec2(0.0, 50.0)),
	};

	unsigned int indices[] = {
		0, 2, 1, 0, 3, 2,
	};

	return new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}
