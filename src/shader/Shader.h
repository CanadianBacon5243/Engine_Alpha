//
// Created by buddm on 11/12/2020.
//

#ifndef ENGINE_ALPHA_SHADER_H
#define ENGINE_ALPHA_SHADER_H


#include <string>
#include "../../src/includes.h"

class Shader {
public:
	explicit Shader(const std::string& fileName);
	virtual ~Shader();

	void bind() const;

private:
	static const unsigned int num_shader = 2;

	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	GLuint m_program;
	GLuint m_shaders[num_shader];
};

#endif //ENGINE_ALPHA_SHADER_H
