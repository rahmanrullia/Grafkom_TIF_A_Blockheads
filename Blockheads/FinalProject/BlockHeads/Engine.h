//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#pragma once
#include "Display.h"

class Engine :
	public Display
{
public:
	Engine(int width, int height, const char* title, bool vsync, bool fullscreen);

private:
	virtual void Init();
	virtual void DeInit();
	virtual void ProcessInput(GLFWwindow* window);
	virtual void Update(double deltaTime);
	virtual void Render();

};

struct Light {
	float x;
	float y;
	float z;
};
