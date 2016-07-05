#pragma once

#include"../models/TexturedModel.h"
#include"../physic/vec3.h"
namespace Adina
{
	class Entity
	{
		TexturedModel model;
		vec3 position;
		float rotX, rotY, rotZ;
		float scale;
	public:
		Entity(TexturedModel model, vec3 position,float rx,float ry,float rz,float sc);
		~Entity();
		void increasePosition(float dx, float dy, float dz);
		void increaseRotation(float dx, float dy, float dz);
		void setTexturedModel(TexturedModel model);
		TexturedModel getTexturedModel();
		void setPosition(vec3 position);
		vec3 getPosition();
		void setRotX(float rotX);
		float getRotX();
		void setRotY(float rotY);
		float getRotY();
		void setRotZ(float rotZ);
		float getRotZ();
		void setScale(float scale);
		float getScale();
	};
}

