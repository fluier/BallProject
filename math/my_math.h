#pragma once

#include"..\physic\mat4.h"
#include"..\physic\vec3.h"
#include"..\entity\Camera.h"
namespace Adina {
	mat4 calcRotationMatrix(const float& rotx, const float& roty, const float& rotz);
	mat4 calcTranslationMatrix(float x, float y, float z);
	float toRadians(float val);
	static mat4 transformation(vec3 pos, float rx, float ry, float rz, float sc);
	mat4 createViewMatrix(Camera& camera);
}