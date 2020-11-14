//
// Created by buddm on 11/3/2020.
//
#include <iostream>
#include "shader/Shader.h"
#include "mesh/Mesh.h"
#include "Display.h"
#include "src/Engine_AlphaConfig.h"
#include "main.h"



int main([[maybe_unused]] int argc, char* argv[]){
	versionPrint(argv);

	Display display(800, 600, "main.cpp", nullptr, nullptr);

	Shader shader("../../src/shader/basicShader");

	Vertex vertices[] = {
			Vertex(glm::vec3(-0.5, -0.5, 0)),
			Vertex(glm::vec3(0, 0.5, 0)),
			Vertex(glm::vec3(0.5, -0.5, 0))
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	while (!glfwWindowShouldClose(display.getWindow())){
		display.processInput();
		Display::clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.bind();
		mesh.draw();

		display.update();
	}

	return 0;
}

void versionPrint(char* argv[]){
	std::cout << argv[0] << " Version " << Engine_Alpha_VERSION_MAJOR << "." << Engine_Alpha_VERSION_MINOR << '\n';
}