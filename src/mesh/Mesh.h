//
// Created by buddm on 11/13/2020.
//

#ifndef ENGINE_ALPHA_MESH_H
#define ENGINE_ALPHA_MESH_H
#include "../includes.h"
#include "Vertex.h"

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int vertices_C);

	void draw();

	virtual ~Mesh();

private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	enum {
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};


#endif //ENGINE_ALPHA_MESH_H
