#pragma once

#include"../entity/Entity.h"
#include"../graphic/GLSLProgram.h"
namespace Adina
{
	class Renderer
	{
		mat4 projection;

	public:
		Renderer();
		~Renderer();
		void init(GLSLProgram& shader);
		void prepare();
		void render(Entity& entity,GLSLProgram& shader);
	private:
		void setProjectionMatrix(const float &angleOfView, const float& aspect, const float &nearPlane,
			const float &farPlane, mat4 &M);

	};
}

