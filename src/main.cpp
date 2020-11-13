//
// Created by buddm on 11/3/2020.
//
#include <iostream>
#include "shaders/Shader.h"
#include "Display.h"
#include "src/Engine_AlphaConfig.h"
#include "main.h"



int main([[maybe_unused]] int argc, char* argv[]){
	versionPrint(argv);

	Display display(800, 600, "main.cpp", nullptr, nullptr);

	Shader shader(R"(C:\Users\buddm\Documents\GitHub\Engine_Alpha\src\shaders\basicShader)");

	while (!glfwWindowShouldClose(display.getWindow())){
		display.processInput();

		glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.bind();

		glfwPollEvents();
		glfwSwapBuffers(display.getWindow());
	}

	return 0;
}

void versionPrint(char* argv[]){
	std::cout << argv[0] << " Version " << Engine_Alpha_VERSION_MAJOR << "." << Engine_Alpha_VERSION_MINOR << '\n';
}