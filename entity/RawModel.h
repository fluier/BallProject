#pragma once

#include<vector>

typedef unsigned int GLuint;
namespace Adina {
	class RawModel
	{
		GLuint m_vboID = 0;
		GLuint m_vbiID = 0;
		int vertexCount;
	public:
		RawModel();
		RawModel(int vboID, int  vertexCount);
		RawModel(int vboID, int vbiID, int  vertexCount);
		~RawModel();
		
		GLuint getVboID();
		GLuint getIndices();
		int getVertexCount();
	};

}
