//-----------------------------------------------------------------------------
// Created by Agastya Darma Laksana on 04/19/20.
// Copyright (c) Facebook, Inc. and its affiliates.
//-----------------------------------------------------------------------------

#include "Display.h"

Display::Display() {

}

Display::~Display()
{
	glfwDestroyWindow(window);
}

void Display::Start(int width, int height, const char* title, bool vsync, bool fullscreen)
{
	// initialize and configure glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// save width and height to use later
	this->screenHeight = height;
	this->screenWidth = width;
	this->title = title;

	// create window
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	window = glfwCreateWindow(width, height, title, fullscreen ? monitor : NULL, NULL);
	if (window == NULL)
	{
		Err("Failed to create GLFW window");
	}

	// if not fullscreen, set window position on center of screen
	if (!fullscreen) {
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		glfwSetWindowPos(window, mode->width / 4, mode->height / 8);
	}

	// set context
	glfwMakeContextCurrent(window);

	// load opengl function glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Err("Failed to initialize GLAD");
	}

	// Call Init function
	Init();

	// vsync
	glfwSwapInterval(vsync ? 1 : 0);

	lastFrame = glfwGetTime() * 1000;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while (!glfwWindowShouldClose(window)) {
		// Calculate framerate and frametime
		double deltaTime = GetDeltaTime();
		GetFPS();

		ProcessInput(window);
		Update(deltaTime);
		Render();

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(window);
		glfwPollEvents();

		//Debug print framerate
		//ShowFPS();
	}

	DeInit();

	glfwTerminate();
}

//Prints out an error message and exits the game
void Display::Err(std::string errorString)
{
	std::cout << errorString << std::endl;
	glfwTerminate();
	exit(1);
}

double Display::GetDeltaTime()
{
	double time = glfwGetTime() * 1000;
	double delta = time - lastFrame;
	lastFrame = time;

	return delta;
}

void Display::GetFPS()
{
	if (glfwGetTime() * 1000 - last > 1000) {
		fps = _fps;
		_fps = 0;
		last += 1000;
	}
	_fps++;
}

static int frameCounter = 0;
void Display::ShowFPS() {
	//print only once every 60 frames
	frameCounter++;
	if (frameCounter == 60) {
		//glfwSetWindowTitle(window, (std::to_string(fps) + " FPS - " + title).c_str());
		std::cout << "FPS " << fps << "         \r";
		frameCounter = 0;
	}
}

void Display::Clear(float r, float g, float b, float a) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(r, g, b, a);
}
