//
// Created by buddm on 11/5/2020.
//

#ifndef ENGINE_ALPHA_DISPLAY_H
#define ENGINE_ALPHA_DISPLAY_H
#include "includes.h"

class Display {
public:
	Display(int width, int height, const char *title, GLFWmonitor* monitor, GLFWwindow* window);
	virtual ~Display();
	GLFWwindow* getWindow();
	void processInput();
	static void clear(float f0, float f1, float f2, float f3);
	void update();

private:
	GLFWwindow* d_Window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};


#endif //ENGINE_ALPHA_DISPLAY_H
