//
// Created by buddm on 11/12/2020.
//

#include "Shader.h"
#include <fstream>
#include <iostream>

static std::string LoadShader(const std::string& fileName);
static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint createShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string &fileName) {
	m_program = glad_glCreateProgram();
	m_shaders[0] = createShader(LoadShader(fileName + ".glvs"), GL_VERTEX_SHADER);
	m_shaders[1] = createShader(LoadShader(fileName + ".glfs"), GL_FRAGMENT_SHADER);

	for (unsigned int m_shader : m_shaders){
		glAttachShader(m_program, m_shader);
	}

	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	checkShaderError(m_program, GL_LINK_STATUS, true, "Linking Failed: ");

	glValidateProgram(m_program);
	checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Validation Failed: ");
}

Shader::~Shader() {
	for (unsigned int m_shader : m_shaders) {
		glDetachShader(m_program, m_shader);
		glDeleteShader(m_shader);
	}

	glDeleteProgram(m_program);
}

void Shader::bind() const {
	glUseProgram(m_program);
}

GLuint createShader(const std::string &text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0){
		std::cerr << "Error: Shader creation failed!" << std::endl;
	}

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	checkShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation failed: ");

	return shader;
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

void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage) {
	GLint success = 0;
	GLchar error [1024] = {0};

	if (isProgram){
		glGetProgramiv(shader, flag, &success);
	} else {
		glGetShaderiv(shader, flag, &success);
	}

	if (success == GL_FALSE){
		if (isProgram){
			glGetProgramInfoLog(shader, sizeof(error), nullptr, error);
		} else {
			glGetShaderInfoLog(shader, sizeof(error), nullptr, error);
		}

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

