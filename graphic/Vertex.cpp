
#include"Vertex.h"

namespace Adina{
	Vertex::Vertex(Position p, ColorRGBA8 c):
		position(p),color(c)
	{
	
	}
	/// Some Helper Function
	void Vertex::setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
	void Vertex::setPosition(float x, float y, float z){
		position.x = x;
		position.y = y;
		position.z = z;
	}
	void Vertex::setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a){
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
	}
	void Vertex::setUV(float u, float v){
		uv.u = u;
		uv.v = v;
	}
	Position::Position(float x, float y, float z):
		x(x),y(y),z(z)
	{
	}
}/*Adina*/