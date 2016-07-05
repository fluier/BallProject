#include "Entity.h"



namespace Adina
{
	Entity::Entity(TexturedModel model, vec3 position, float rx, float ry, float rz, float sc):
		model(model),position(position),rotX(rz),rotY(ry),rotZ(rz),scale(sc)
	{
	}


	Entity::~Entity()
	{
	}
	void Entity::increasePosition(float dx, float dy, float dz)
	{
		position.x += dx;
		position.y += dy;
		position.z += dz;
	}
	void Entity::increaseRotation(float dx, float dy, float dz)
	{
		this->rotX += dx;
		this->rotY += dy;
		this->rotZ += dz;
	}
	void Entity::setTexturedModel(TexturedModel model)
	{
		this->model = model;
	}
	TexturedModel Entity::getTexturedModel()
	{
		return model;
	}
	void Entity::setPosition(vec3 position)
	{
		this->position = position;
	}
	vec3 Entity::getPosition()
	{
		return position;
	}
	void Entity::setRotX(float rotX)
	{
		this->rotX = rotX;
	}
	float Entity::getRotX()
	{
		return rotX;
	}
	void Entity::setRotY(float rotY)
	{
		this->rotY = rotY;
	}
	float Entity::getRotY()
	{
		return rotY;
	}
	void Entity::setRotZ(float rotZ)
	{
		this->rotZ = rotZ;
	}
	float Entity::getRotZ()
	{
		return rotZ;
	}
	void Entity::setScale(float scale)
	{
		this->scale = scale;
	}
	float Entity::getScale()
	{
		return scale;
	}
}
