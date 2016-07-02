#include<GL/glew.h>
#include<algorithm>
#include<iostream>
#include "Renderer.h"

#include"../graphic/Vertex.h"

namespace Adina
{
	Renderer::Renderer()
	{
	}


	Renderer::~Renderer()
	{
	}
	void Renderer::prepare()
	{
		glClearColor(0.0, 0.0, 0.0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Renderer::render(RawModel model)
	{
		glBindBuffer(GL_ARRAY_BUFFER, model.getVboID());
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,model.getIndices());
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, position));
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
		//glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
		glDrawElements(GL_LINES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
		//glDrawElements(GL_TRIANGLES,model.getVertexCount(), GL_UNSIGNED_INT,0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

	}
}