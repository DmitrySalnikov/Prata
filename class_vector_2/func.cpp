#include "header.h"
#include <iostream>
#include <cmath>

namespace VECTOR {
	Vector::Vector(double d, double a, char m) {
		if ('p'==m) {
			while (a>180)
				a-=360;
			while (a<=-180)
				a+=360;
			dist_c=d;
			angle_c=a/RAD_TO_DEG;
			course_c=a;
		}
		else {
			dist_c=std::sqrt(d*d+a*a);
			angle_c=std::atan2(a, d);
			course_c=angle_c*RAD_TO_DEG;
			if (m!='r')
				std::cout<<"Error mode, coordinates taken as rectangular\n";
		}
	}

	void Vector::set(double d, double a, char m) {
		if ('p'==m) {
			while (a>180)
				a-=360;
			while (a<=-180)
				a+=360;
			dist_c=d;
			angle_c=a/RAD_TO_DEG;
			course_c=a;
		}
		else {
			dist_c=std::sqrt(d*d+a*a);
			angle_c=std::atan2(a, d);
			course_c=angle_c*RAD_TO_DEG;
			if (m!='r')
				std::cout<<"Error mode, coordinates taken as rectangular\n";
		}	
	}

	void Vector::operator+=(const Vector & v) {
		course_c=v.course_c;
		double x=dist_c*std::cos(angle_c)+v.dist_c*std::cos(v.angle_c);
		double y=dist_c*std::sin(angle_c)+v.dist_c*std::sin(v.angle_c);
		dist_c=std::sqrt(x*x+y*y);
		angle_c=atan2(y, x);
		while (angle_c*RAD_TO_DEG>180)
			angle_c-=360/RAD_TO_DEG;
		while (angle_c*RAD_TO_DEG<=-180)
			angle_c+=360/RAD_TO_DEG;
	}

	void Vector::operator*=(double n) {
		dist_c*=n;
	}

	double Vector::dist() const {
		return dist_c;
	}

	double Vector::course() const {
		return course_c;
	}

	double Vector::angle() const {
		return angle_c;
	}
};