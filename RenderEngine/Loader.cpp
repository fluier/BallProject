#include<GL\glew.h>

#include<iostream>
#include "Loader.h"

namespace  Adina {
	std::vector<GLuint>  vbos;
	Loader::Loader()
	{
	}


	Loader::~Loader()
	{
	}
	RawModel Loader::loadToVAO(std::vector<float> positions)
	{
		GLuint vaoID = storeDataInAttributeList(0, positions);
		return RawModel(vaoID, positions.size());
	}
	RawModel Loader::loadToVAO(std::vector<Vertex> verts)
	{
		GLuint vaoID = storeDataInAttributeList(verts);
		return RawModel(vaoID, verts.size());
	}
	RawModel &Loader::loadToVAO(const std::vector<Vertex> verts, const std::vector<GLuint> indices)
	{
		GLuint vaoID = storeDataInAttributeList(verts);
		GLuint vaiID = storeIndicesInAttributeList(indices);
		return RawModel(vaoID, vaiID, indices.size());
	}
	void Loader::clearUP()
	{
		std::cout << "Facem curatenie" << std::endl;
		for (GLuint vbo : vbos) {
			glDeleteBuffers(1, &vbo);
		}
	}
	GLuint Loader::storeDataInAttributeList(int attributeNumber, std::vector<float> data)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), &data[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		return vboID;
	}
	GLuint Loader::storeDataInAttributeList(std::vector<Vertex> verts)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), verts.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		return vboID;
	}
	GLuint Loader::storeIndicesInAttributeList(std::vector<GLuint> indices)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		return vboID;
	}
}