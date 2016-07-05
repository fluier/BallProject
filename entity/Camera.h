#pragma once
#include<SDL2\SDL.h>

#include"../physic/vec3.h"

namespace Adina {
	class Camera
	{
		vec3 position;
		float pitch;
		float yaw;
		float roll;
	public:
		Camera();
		~Camera();
		void init(vec3 position, float pitch, float yaw, float roll);
		void input(SDL_Event& evnt);
		vec3 getPosition();
		float getPitch();
		float getYaw();
		float getRoll();
	};
}

