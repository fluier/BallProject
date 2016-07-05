#pragma once

#include"RawModel.h"
#include"../texture/ModelTexture.h"

namespace Adina
{
	class TexturedModel
	{
		RawModel rawModel;
		ModelTexture texture;
	public:
		TexturedModel();
		TexturedModel(RawModel rawModel, ModelTexture texture);
		~TexturedModel();
		RawModel getRawModel();
		ModelTexture getModelTexture();
	};
}
