#pragma once

#include<vector>

#include"graphic\Window.h"
#include"graphic\GLSLProgram.h"
#include"RenderEngine\Loader.h"
#include"RenderEngine\Renderer.h"
#include"entity\Camera.h"
namespace Adina {

	class MainClass
	{
		bool GAME_IS_RUNNING;
		Window window;
		GLSLProgram m_shader;
		Loader m_loader;
		Renderer* m_renderer;
		Camera m_camera;

	public:
		MainClass();
		~MainClass();

		void init();
		void run();
		void update();
		void draw();
		void input(SDL_Event& evnt);
		void exit();

		///
	private:
		void initShaders();
	};


}