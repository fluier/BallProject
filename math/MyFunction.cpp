#include "MyFunction.h"

#include"Complex.h"

#include<iostream>

typedef unsigned int GLuint;
#define M_PI  3.14159265358979323846
#define D_M_PI 2*M_PI
namespace Adina {

	MyFunction::MyFunction()
	{
	}


	MyFunction::~MyFunction()
	{
	}

	GraphicModel MyFunction::f1()
	{
		GraphicModel rez;
		std::vector<Vertex> vertex = {
			Vertex(Position(-1.0f,+1.0f,-0.0f),ColorRGBA8(255,0,0,255)),
			Vertex(Position(-1.0f,-1.0f,-0.0f),ColorRGBA8(0,255,0,255)),
			Vertex(Position(+1.0f,+1.0f,-0.0f),ColorRGBA8(0,0,255,255)),
			Vertex(Position(+1.0f,-1.0f,-0.0f),ColorRGBA8(0,0,255,255)),
		};
		std::vector<GLuint> indices = { 0,1,2 ,0 };
		rez.init(vertex, indices);
		return rez;
	}
	/*
			a
		--------
		b  + s

	*/
	GraphicModel MyFunction::f2()
	{
		float x = 0;
		float y = 0;
		bool b = true;
		float  rezolutie = M_PI/12;
		std::vector<Vertex> vertex;
		std::vector<GLuint> indices;
		GraphicModel rez;
		unsigned int  counter = 0;
		for (float i = 0; i < D_M_PI; i += rezolutie) {
			x = 4 * cos(i);
			y = 4 * sin(i);
			
			if (b) {
				vertex.push_back(Vertex(Position(x, y, 0), ColorRGBA8(255, 0, 0, 255)));
				b = false;
			}
			else {
				vertex.push_back(Vertex(Position(x, y, 0), ColorRGBA8(0, 0, 255, 255)));
				b = true;
			}

			if (i < D_M_PI - rezolutie) {
				indices.push_back(counter);
				indices.push_back(counter + 1);
				counter++;
			}
		}

		rez.init(vertex, indices);
		return rez;
	}

	GraphicModel MyFunction::f3()
	{
		float x = 0;
		float y = 0;
		bool b = true;
		float  rezolutie = M_PI / 12;
		std::vector<Vertex> vertex;
		std::vector<GLuint> indices;
		GraphicModel rez;
		unsigned int  counter = 0;
		for (float i = 0; i < D_M_PI; i += rezolutie) {
			x =  i;
			y += 1 / exp(i);

			if (b) {
				vertex.push_back(Vertex(Position(x, y, 0), ColorRGBA8(255, 0, 0, 255)));
				b = false;
			}
			else {
				vertex.push_back(Vertex(Position(x, y, 0), ColorRGBA8(0, 0, 255, 255)));
				b = true;
			}

			if (i < D_M_PI - rezolutie) {
				indices.push_back(counter);
				indices.push_back(counter + 1);
				counter++;
			}
		}

		rez.init(vertex, indices);
		return rez;
	}

}