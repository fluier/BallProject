#pragma once

#include<vector>

#include"../graphic/Vertex.h"

namespace Adina
{
	class GraphicModel
	{
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;
	public:
		GraphicModel();
		~GraphicModel();
		void init(std::vector<Vertex>vertices, std::vector<unsigned int> indices);
		std::vector<Vertex> getVertices()const;
		std::vector<unsigned int>  getIndices()const;
	};

}
