#pragma once

typedef unsigned char GLubyte;

namespace Adina
{
	struct Position
	{
		float x;
		float y;
		float z;
		Position(float x, float y, float z);
	};
	struct ColorRGBA8
	{
		ColorRGBA8() :
			r(0), g(0), b(0), a(0)	{	}
		ColorRGBA8(GLubyte r, GLubyte g, GLubyte b, GLubyte a):
			r(r), g(g), b(b), a(a){	}
		GLubyte r;
		GLubyte g;
		GLubyte b;
		GLubyte a;
	};
	struct UV
	{
		float u;
		float v;
		UV(float u, float v) :
			u(u), v(v) {}
	};
	struct Vertex
	{
		Position position;
		ColorRGBA8 color;
		UV uv;

		Vertex(Position p, ColorRGBA8 c);
		Vertex(Position p, UV uv, ColorRGBA8 c);
		void setPosition(float x, float y);
		void setPosition(float x, float y, float z);
		void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a);
		void setUV(float u, float v);
	};
}