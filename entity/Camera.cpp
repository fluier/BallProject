#include "Camera.h"


namespace Adina {

	Camera::Camera()
	{
	}


	Camera::~Camera()
	{
	}

	void Camera::init(vec3 position, float pitch, float yaw, float roll)
	{
		this->position = position;
		this->pitch = pitch;
		this->yaw = yaw;
		this->roll = roll;
	}
	void Camera::input(SDL_Event & evnt)
	{
		switch (evnt.key.keysym.sym)
		{
		case SDLK_w:
			position.z -= 0.02f;
			break;
		case SDLK_d:
			position.x += 0.02f;
			break;
		case SDLK_a:
			position.x -= 0.02f;
			break;
		default:
			break;
		}
	}
	vec3 Camera::getPosition()
	{
		return position;
	}

	float Camera::getPitch()
	{
		return pitch;
	}

	float Camera::getYaw()
	{
		return yaw;
	}

	float Camera::getRoll()
	{
		return roll;
	}

}