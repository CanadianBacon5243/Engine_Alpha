//
// Created by buddm on 11/3/2020.
//
#include "src/Engine_AlphaConfig.h"
#include "main.h"


int main(int argc, char* argv[]){
	versionPrint(argv);

	auto display = new Display(800, 600, "main.cpp", nullptr, nullptr);

	while (!glfwWindowShouldClose(display->getWindow())){
		display->processInput();

		glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(display->getWindow());
	}

	delete display;
	return 0;
}

void versionPrint(char* argv[]){
	std::cout << argv[0] << " Version " << Engine_Alpha_VERSION_MAJOR << "." << Engine_Alpha_VERSION_MINOR << '\n';
}