#pragma once

#include"ModelTexture.h"

#include<string>
namespace Adina {

	class ImageLoader
	{
	public:
		static ModelTexture loadPNG(std::string filePath);
	};

}

