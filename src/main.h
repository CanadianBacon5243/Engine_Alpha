//
// Created by buddm on 11/3/2020.
//

#ifndef ENGINE_ALPHA_MAIN_H
#define ENGINE_ALPHA_MAIN_H
#include <iostream>
#include <array>
#include <thread>
#include <chrono>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Display.h"

void versionPrint(char* argv[]);

void colorChange(std::array<GLfloat, 4>*& rgba);
#endif //ENGINE_ALPHA_MAIN_H
