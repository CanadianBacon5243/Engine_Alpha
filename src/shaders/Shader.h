//
// Created by buddm on 11/12/2020.
//

#ifndef ENGINE_ALPHA_SHADER_H
#define ENGINE_ALPHA_SHADER_H


#include <string>
#include <fstream>
#include <glad/glad.h>

class Shader {
public:
	Shader(const std::string& fileName);
	virtual ~Shader();

	void bind();

private:
	static const unsigned int num_shader = 2;

	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	GLuint m_program;
	GLuint m_shaders[num_shader];
};

static std::string LoadShader(const std::string& fileName);
static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
#endif //ENGINE_ALPHA_SHADER_H
