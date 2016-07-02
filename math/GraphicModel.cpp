#include "GraphicModel.h"

#include<stdio.h>

namespace Adina
{
	GraphicModel::GraphicModel()
	{

	}


	GraphicModel::~GraphicModel()
	{

	}
	void GraphicModel::init(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
	{
		m_vertices = vertices;
		m_indices = indices;
	}
	std::vector<Vertex> GraphicModel::getVertices()const
	{
		return m_vertices;
	}
	std::vector<unsigned int>  GraphicModel::getIndices()const
	{
		return m_indices;
	}
}