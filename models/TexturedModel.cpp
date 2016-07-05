#include "TexturedModel.h"



namespace Adina
{
	TexturedModel::TexturedModel()
	{
	}

	TexturedModel::TexturedModel(RawModel rawModel, ModelTexture texture):
		rawModel(rawModel), texture(texture)
	{
	}


	TexturedModel::~TexturedModel()
	{
	}

	RawModel TexturedModel::getRawModel()
	{
		return rawModel;
	}

	ModelTexture TexturedModel::getModelTexture()
	{
		return texture;
	}

}