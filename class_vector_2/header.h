#ifndef HEADER_
#define  HEADER_

namespace VECTOR {
	const double RAD_TO_DEG=57.2957795130823;

	class Vector {
		double dist_c;
		double angle_c;
		double course_c;
	public:
		Vector(double d=0.0, double a=0.0, char m='p');
		void set(double d=0.0, double a=0.0, char m='p');
		~Vector(){}
		void operator+=(const Vector &);
		void operator*=(double);
		double dist() const;
		double course() const;
		double angle() const;
	};
};

#endif