//
// Created by buddm on 11/12/2020.
//

#include <iostream>
#include "Shader.h"

Shader::Shader(const std::string &fileName) {

}

static std::string LoadShader(const std::string& fileName){
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open()){
		while (file.good()){
			getline(file, line);
			output.append(line + "\n");
		}
	} else {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}
	return output;
}