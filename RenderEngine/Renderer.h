#pragma once

#include"../models/RawModel.h"

namespace Adina
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();
		void prepare();
		void render(RawModel model);
	};
}

