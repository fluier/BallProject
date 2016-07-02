#pragma once

#include<vector>
#include"../entity/RawModel.h"
#include"../graphic/Vertex.h"

typedef unsigned int GLuint;

namespace Adina {
	class Loader
	{
	public:
		Loader();
		~Loader();
		RawModel loadToVAO(std::vector<float> positions);
		RawModel loadToVAO(std::vector<Vertex> verts);
		RawModel& loadToVAO(const std::vector<Vertex> verts, const std::vector<GLuint> indices);
		void clearUP();
	private:
		GLuint storeDataInAttributeList(int attributeNumber, std::vector<float> data);
		GLuint storeDataInAttributeList(std::vector<Vertex> verts);
		GLuint storeIndicesInAttributeList(std::vector<GLuint> indices);
	};
}

