#include "Complex.h"

#include<math.h>

namespace Adina {
	Complex::Complex():
		x(0),y(0)
	{

	}

	Complex::Complex(float x, float y) :
		x(x), y(y)
	{
	}


	Complex::~Complex()
	{
	}

	Complex & Complex::operator+(const Complex & b)
	{
		return Complex(x + b.x, y + b.y);
	}

	Complex & Complex::operator-(const Complex & b)
	{
		return Complex(x - b.x, y - b.y);
	}
	/*************************************************************
	(a  +  bi)*(c  + di)  = (ac - bd) + (bc + ad)i
	*/
	Complex & Complex::operator*(const Complex & b)
	{
		return Complex(x * b.x - y * b.y, y * b.x + x * b.y);
	}
	/*************************************************************
		a + bi   ab + bd       bc - ad
		------ = ---------- + ---------- i
		c + di   c^2 + d^2     c^2 + d^2
	*/
	Complex & Complex::operator/(const Complex & b)
	{
		float c = b.x;
		float d = b.y;
		float cd = pow(c, 2) + pow(d, 2);
		return Complex((x * y - y * b.y)/ cd, (y * b.x - x * b.y)/cd);
	}

	bool Complex::operator==(const Complex & b)
	{
		if (x != b.x || y != b.y) {
			return false;
		}
		return true;
	}

}