#include "Complex.h"

Complex operator*(double a, const Complex & z) {
	return z*a;
}

ostream & operator<<(ostream & os, const Complex & z) {
	os<<"("<<z.x<<", "<<z.y<<")";
	return os;
}

istream & operator>>(istream & is, Complex & z) {
	cout<<"Enter Re(z): ";
	is>>z.x;
	if (!is)
		return is;
	cout<<"Enter Im(z): ";
	is>>z.y;
	return is;
}
