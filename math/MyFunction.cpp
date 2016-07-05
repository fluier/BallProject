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
			Vertex(Position(-1.0f,+1.0f,-1.0f),ColorRGBA8(255,0,0,255)),
			Vertex(Position(-1.0f,-1.0f,-1.0f),ColorRGBA8(0,255,0,255)),
			Vertex(Position(+1.0f,+1.0f,-1.0f),ColorRGBA8(0,0,255,255)),
			Vertex(Position(+1.0f,-1.0f,-1.0f),ColorRGBA8(0,0,255,255)),
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

	GraphicModel MyFunction::rectangle()
	{
		std::vector<Vertex> vertex;
		std::vector<GLuint> indices;
		vertex.push_back(Vertex(Position(-1.0f, +1.0f, 0.0f),UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
		vertex.push_back(Vertex(Position(-1.0f, -1.0f, 0.0f),UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
		vertex.push_back(Vertex(Position(+1.0f, -1.0f, 0.0f),UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
		vertex.push_back(Vertex(Position(+1.0f, +1.0f, 0.0f),UV(1, 0), ColorRGBA8(255, 0, 0, 255)));

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(3);

		indices.push_back(3);
		indices.push_back(1);
		indices.push_back(2);

		GraphicModel rez;
		rez.init(vertex, indices);
		return rez;
	}

	GraphicModel MyFunction::cube()
	{
		std::vector<Vertex> vertex;
		std::vector<GLuint> indices;

			vertex.push_back(Vertex(Position(-0.5f, +0.5f, -0.5f), UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, -0.5f, -0.5f), UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, -0.5f, -0.5f), UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
			vertex.push_back(Vertex(Position(+0.5f, +0.5f, -0.5f), UV(1, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, +0.5f, +0.5f), UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, -0.5f, +0.5f), UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, -0.5f, +0.5f), UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
			vertex.push_back(Vertex(Position(+0.5f, +0.5f, +0.5f), UV(1, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, +0.5f, -0.5f), UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, -0.5f, -0.5f), UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, -0.5f, +0.5f), UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
			vertex.push_back(Vertex(Position(+0.5f, +0.5f, +0.5f), UV(1, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, +0.5f, -0.5f), UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, -0.5f, -0.5f), UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, -0.5f, +0.5f), UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
			vertex.push_back(Vertex(Position(-0.5f, +0.5f, +0.5f), UV(1, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, +0.5f, +0.5f), UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, +0.5f, -0.5f), UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, +0.5f, -0.5f), UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
			vertex.push_back(Vertex(Position(+0.5f, +0.5f, +0.5f), UV(1, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, -0.5f, +0.5f), UV(0, 0), ColorRGBA8(255, 0, 0, 255)));
			vertex.push_back(Vertex(Position(-0.5f, -0.5f, -0.5f), UV(0, 1), ColorRGBA8(0, 255, 0, 255)));
			vertex.push_back(Vertex(Position(+0.5f, -0.5f, -0.5f), UV(1, 1), ColorRGBA8(0, 0, 255, 255)));
			vertex.push_back(Vertex(Position(+0.5f, -0.5f, +0.5f), UV(1, 0), ColorRGBA8(255, 0, 0, 255)));

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(3);
		indices.push_back(3);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(4); 
		indices.push_back(5);
		indices.push_back(7);
		indices.push_back(7);
		indices.push_back(5);
		indices.push_back(6);
		indices.push_back(8);
		indices.push_back(9);
		indices.push_back(11);
		indices.push_back(11);
		indices.push_back(9);
		indices.push_back(10);
		indices.push_back(12);
		indices.push_back(13);
		indices.push_back(15);
		indices.push_back(15);
		indices.push_back(13);
		indices.push_back(14);
		indices.push_back(16);
		indices.push_back(17);
		indices.push_back(19);
		indices.push_back(19);
		indices.push_back(17); 
		indices.push_back(18);
		indices.push_back(20);
		indices.push_back(21); 
		indices.push_back(23);
		indices.push_back(23);
		indices.push_back(21); 
		indices.push_back(22);

		GraphicModel rez;
		rez.init(vertex, indices);
		return rez;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}