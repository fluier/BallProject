#include "MainClass.h"
#include<iostream>

#include"graphic\Vertex.h"

#include"math\MyFunction.h"
#include"math\GraphicModel.h"

#include"entity\Entity.h"
#include"math\my_math.h"

Adina::RawModel model;
Adina::MyFunction f;
Adina::TexturedModel* texturedModel;
Adina::Entity* entity;

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
		GraphicModel  m1 = f.cube();
		window.create("Adina", 500, 500, 0);
		initShaders();
		
		m_renderer = new Renderer();
		m_renderer->init(m_shader);

		model = m_loader.loadToVAO(m1.getVertices(),m1.getIndices());
		texturedModel = new TexturedModel(model, m_loader.loadTexture("res/tex1.png"));
		entity = new Entity(*texturedModel,vec3(0,0,-10.0f),0.0f, 0.0f, 0.0f, 1.0f);
		m_camera.init(vec3(0,0,0),0,0,0);
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
		SDL_Event evnt;
		while (SDL_PollEvent(&evnt)) {
			input(evnt);
			m_camera.input(evnt);
		}
	}
	void MainClass::draw()
	{
		mat4 viewMatrix = createViewMatrix(m_camera);
		entity->increaseRotation(0.001, 0.001, 0);
		m_shader.use();
		m_shader.setUniformMatrix4fv("viewMatrix", viewMatrix);
		m_renderer->render(*entity, m_shader);
		m_shader.unuse();

		window.swapBuffer();
	}

	void MainClass::input(SDL_Event& evnt)
	{
			switch (evnt.type)
			{
			case SDL_QUIT:
				exit();
				break;
			default:
				break;
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
		m_shader.addAttribute("textureCoords");
		m_shader.linkShaders();
	}

}
int main() {
	Adina::MainClass app;
	app.run();

	return 0;
}