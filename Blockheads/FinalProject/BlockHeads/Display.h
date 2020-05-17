//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Display
{
public:
	Display();
	~Display();

	void Start(int width, int height, const char* title, bool vsync, bool fullscreen);
	void Clear(float r, float g, float b, float a);
	void Err(std::string errorString);
	double GetDeltaTime();
	void GetFPS();
	void ShowFPS();
protected:
	GLFWwindow* window;
	double lastFrame = 0;
	int fps = 0, _fps = 0, last = 0, screenWidth, screenHeight;
	const char* title;

	virtual void ProcessInput(GLFWwindow* window) = 0;
	virtual void Render() = 0;
	virtual void Update(double deltaTime) = 0;
	virtual void Init() = 0;
	virtual void DeInit() = 0;
};
