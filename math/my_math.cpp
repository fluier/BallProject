#include "my_math.h"

#include<math.h>

#define M_PI  3.14159265358979323846

namespace Adina {
	mat4 calcRotationMatrix(const float& rotx,const float& roty, const float& rotz)
	{	
		mat4 rez; rez.setIdentity();
		mat4 rx,ry,rz;
		rx.setIdentity();
		ry.setIdentity();
		rz.setIdentity();
		if(rotx)
			rx.rotX(rotx);
		if (roty)
			ry.rotY(roty);
		if (rotz)
			rz.rotZ(rotz);
		rez = rz * ry * rx;
		return rez;
	}
	/****************************************************************
	1 0 0 x
	0 1 0 y
	0 0 1 z
	0 0 0 1
	*/
	mat4 calcTranslationMatrix(float x, float y, float z)
	{
		mat4 rez;
		rez.setIdentity();
		rez.val[3][0] = x;
		rez.val[3][1] = y;
		rez.val[3][2] = z;
		return rez;
	}
	float toRadians(float val)
	{
		return val * 180 / M_PI;
	}
	mat4 transformation(vec3 pos, float rx, float ry, float rz, float sc)
	{
		mat4 rez;
		rez.setIdentity();

		return mat4();
	}
	mat4 createViewMatrix(Camera & camera)
	{
		mat4 viewMatrix; viewMatrix.setIdentity();
		viewMatrix = calcRotationMatrix(0, camera.getYaw(), 0);

		vec3 negativeCamera = vec3(-camera.getPosition().x, -camera.getPosition().y, -camera.getPosition().z);

		viewMatrix = viewMatrix * calcTranslationMatrix(negativeCamera.x, negativeCamera.y, negativeCamera.z);
		return viewMatrix;
	}
}