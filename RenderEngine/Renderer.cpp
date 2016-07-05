#include<GL/glew.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include "Renderer.h"

#include"../graphic/Vertex.h"
#include"../math/my_math.h"

#define M_PI  3.14159265358979323846

namespace Adina
{
	Renderer::Renderer()
	{
	
	}


	Renderer::~Renderer()
	{
	}
	void Renderer::init(GLSLProgram & shader)
	{
		setProjectionMatrix(30,1, 1, -100, projection);

		shader.use();
		shader.setUniformMatrix4fv("projectionMatrix", projection);
		shader.unuse();
	}
	void Renderer::prepare()
	{
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0, 0.0, 0.0, 1);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	}
	float time;
	void Renderer::render(Entity& entity,GLSLProgram& shader)
	{
		mat4 rotMatrix;
		mat4 translationMatrix;
		mat4 transformMatrix;

		prepare();
		time += 0.0001f;
		entity.increaseRotation(0.0, 0.0, 0.0);
		entity.increasePosition(0, 0, 0);

		translationMatrix = calcTranslationMatrix(entity.getPosition().x, entity.getPosition().y, entity.getPosition().z);
		rotMatrix = calcRotationMatrix(entity.getRotX(), entity.getRotY(), entity.getRotZ());
		transformMatrix = rotMatrix * translationMatrix;
		
		
		shader.setUniformMatrix4fv("transformMatrix", transformMatrix);

		TexturedModel texturedModel = entity.getTexturedModel();
		RawModel model = texturedModel.getRawModel();
		glBindBuffer(GL_ARRAY_BUFFER, model.getVboID());
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,model.getIndices());
		glActiveTexture(GL_TEXTURE0);
		texturedModel.getModelTexture().bind();
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, position));
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
		glVertexAttribPointer(2, 2, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, uv));
		//glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
		//glDrawElements(GL_LINES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
		glDrawElements(GL_TRIANGLES,model.getVertexCount(), GL_UNSIGNED_INT,0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
		texturedModel.getModelTexture().unbind();

	}
	void Renderer::setProjectionMatrix(
		const float & angleOfView, const float& aspect,
		const float & nearPlane, const float &farPlane,
		mat4 & M)
	{
	
		float m00 = 1 / tan(angleOfView * (float)M_PI / 360);
		float m11 = aspect / tan(angleOfView * (float)M_PI / 360);
		float m22 = (nearPlane + farPlane) / (nearPlane - farPlane);
		float m23 = (2 * nearPlane * farPlane) / (nearPlane - farPlane);

		M.val[0][0] = m00; M.val[1][0] = 0;   M.val[2][0] = 0;    M.val[3][0] = 0;
		M.val[0][1] = 0;   M.val[1][1] = m11; M.val[2][1] = 0;    M.val[3][1] = 0;
		M.val[0][2] = 0;   M.val[1][2] = 0;   M.val[2][2] = m22;  M.val[3][2] = m23;
		M.val[0][3] = 0;   M.val[1][3] = 0;   M.val[2][3] = -1;   M.val[3][3] = 0;
		
	}
}