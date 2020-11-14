//
// Created by buddm on 11/13/2020.
//

#ifndef ENGINE_ALPHA_VERTEX_H
#define ENGINE_ALPHA_VERTEX_H
#include "../includes.h"
#include <glm/glm.hpp>

class Vertex {
public:
	explicit Vertex(const glm::vec3& pos);

private:
	glm::vec3 pos;
};


#endif //ENGINE_ALPHA_VERTEX_H
