#include "MainClass.h"
#include<iostream>

#include"graphic\Vertex.h"

#include"math\MyFunction.h"
#include"math\GraphicModel.h"

Adina::RawModel model;
Adina::MyFunction f;

namespace Adina {


	MainClass::MainClass()
	{
	}


	MainClass::~MainClass()
	{
		m_shader.dispose();
		m_loader.clearUP();
	}
	void MainClass::init()
	{
		GraphicModel  m1 = f.f2();
		window.create("Adina", 500, 500, 0);
		initShaders();
		
		projection.setToZero();
		setProjectionMatrix(60, 1, -100, projection);

		model = m_loader.loadToVAO(m1.getVertices(),m1.getIndices());
	}

	void MainClass::run()
	{
		GAME_IS_RUNNING = true;
		init();
		while (GAME_IS_RUNNING) {
			update();
			draw();
		}
	}

	void MainClass::update()
	{
		input();
	}
	float time;
	void MainClass::draw()
	{
		m_renderer.prepare();

		calcTranslationMatrix(translationMatrix, 0, 0, -10);
		calcRotationMatrix(rotMatrix, time);
		transformMatrix = projection * rotMatrix * translationMatrix;
		m_shader.use();
		m_shader.setUniformMatrix4fv("transformMatrix", transformMatrix);
	
		m_renderer.render(model);

		m_shader.unuse();
		window.swapBuffer();
	}

	void MainClass::input()
	{
		SDL_Event evnt;
		while (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				exit();
				break;
			case SDLK_ESCAPE:
				break;
			default:
				break;
			}
		}
	}

	void MainClass::exit()
	{
		GAME_IS_RUNNING = false;
	}

	void MainClass::initShaders()
	{
		m_shader.compileShaders("Shaders/vertex.txt", "Shaders/fragment.txt");
		m_shader.addAttribute("vertexPosition");
		m_shader.addAttribute("vertexColor");
		m_shader.linkShaders();
	}

}
int main() {
	Adina::MainClass app;
	app.run();

	return 0;
}