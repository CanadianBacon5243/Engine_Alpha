//
// Created by buddm on 11/3/2020.
//

#ifndef ENGINE_ALPHA_MAIN_H
#define ENGINE_ALPHA_MAIN_H
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void versionPrint(char* argv[]);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);
#endif //ENGINE_ALPHA_MAIN_H
