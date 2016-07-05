#include<GL\glew.h>

#include<iostream>

#include"ModelTexture.h"


namespace Adina {
	void ModelTexture::bind() {
		glBindTexture(GL_TEXTURE_2D, id);
	}
	void ModelTexture::unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}