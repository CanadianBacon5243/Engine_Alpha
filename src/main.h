//
// Created by buddm on 11/3/2020.
//

#ifndef ENGINE_ALPHA_MAIN_H
#define ENGINE_ALPHA_MAIN_H
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void versionPrint(char* argv[]){
	std::cout << argv[0] << " Version " << Engine_Alpha_VERSION_MAJOR << "." << Engine_Alpha_VERSION_MINOR << '\n';
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}
#endif //ENGINE_ALPHA_MAIN_H
