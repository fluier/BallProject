#include<GL\glew.h>

#include "RawModel.h"

namespace Adina {
	RawModel::RawModel()
	{
	}
	RawModel::RawModel(int vboID, int  vertexCount):
		m_vboID(vboID),vertexCount(vertexCount)
	{
	}

	RawModel::RawModel(int vboID, int vbiID, int vertexCount):
		m_vboID(vboID),m_vbiID(vbiID), vertexCount(vertexCount)
	{
	}


	RawModel::~RawModel()
	{
	}
	GLuint RawModel::getVboID()
	{
		return m_vboID;
	}
	GLuint RawModel::getIndices()
	{
		return m_vbiID;
	}
	int RawModel::getVertexCount()
	{
		return vertexCount;
	}
}