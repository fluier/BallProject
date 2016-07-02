#pragma once

namespace Adina {
	class Complex
	{
		float x;
		float y;
	public:
		Complex();
		Complex(float x, float y);
		~Complex();
		Complex &operator+(const Complex& b);
		Complex &operator-(const Complex& b);
		Complex &operator*(const Complex& b);
		Complex &operator/(const Complex& b);
		bool operator==(const Complex& b);
	};

}
