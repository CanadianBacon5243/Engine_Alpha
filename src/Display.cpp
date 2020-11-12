//
// Created by buddm on 11/5/2020.
//

#include "Display.h"

Display::Display(int width, int height, const char *title, GLFWmonitor* monitor, GLFWwindow* window) {
	if (!glfwInit()){
		fprintf(stderr, "GLFW failed to initialize\n");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	d_Window = glfwCreateWindow(width, height, title, monitor, window);

	if (d_Window == nullptr){
		fprintf(stderr, "Failed to create GLFW window\n");
		glfwTerminate();
		std::exit(-1);
	}

	glfwMakeContextCurrent(d_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		fprintf(stderr, "Failed to initialize GLAD\n");
		glfwTerminate();
		std::exit(-1);
	}

	glad_glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(d_Window, Display::framebuffer_size_callback);
}

void Display::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

GLFWwindow *Display::getWindow() {
	return d_Window;
}

void Display::processInput() {
	if (glfwGetKey(d_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(d_Window, true);
	}
}

Display::~Display() {
	glfwTerminate();
}
