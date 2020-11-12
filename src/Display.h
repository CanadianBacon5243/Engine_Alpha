//
// Created by buddm on 11/5/2020.
//

#ifndef ENGINE_ALPHA_DISPLAY_H
#define ENGINE_ALPHA_DISPLAY_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Display {
public:
	Display(int width, int height, const char *title, GLFWmonitor* monitor, GLFWwindow* window);
	virtual ~Display();
	GLFWwindow* getWindow();
	void processInput();

private:
	GLFWwindow* d_Window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};


#endif //ENGINE_ALPHA_DISPLAY_H
