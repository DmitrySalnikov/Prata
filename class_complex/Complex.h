#ifndef HEADER_
#define HEADER_

#include "io.h"

class Complex {
	double x;
	double y;
public:
	Complex(double a=0, double b=0) {x=a; y=b;}
	~Complex() {}
	Complex operator+(const Complex & z) const {return Complex(x+z.x, y+z.y);}
	Complex operator-(const Complex & z) const {return Complex(x-z.x, y-z.y);}
	Complex operator*(const Complex & z) const {return Complex(x*z.x-y*z.y, x*z.y+y*z.x);}
	Complex operator*(double a) const {return Complex(x*a, y*a);}
	Complex operator~() const {return Complex(x, -y);}
	friend ostream & operator<<(ostream &, const Complex &);
	friend istream & operator>>(istream &, Complex &);
};

Complex operator*(double, const Complex &);

#endif
