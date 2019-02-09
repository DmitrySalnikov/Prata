#ifndef _HEADER
#define _HEADER

#include <iostream>

class Time {
	int hours;
	int minutes;
public:
	Time(int h=0, int m=0) {hours=h+m/60; minutes=m%60;}
	void addh(int h=1) {hours+=h;}
	void addmin(int m=1) {hours+=m/60; minutes+=m%60;}
	void reset(int h=0, int m=0) {hours=h+m/60; minutes=m%60;}
	Time operator+(const Time &) const;
	Time operator-(const Time &) const;
	Time operator*(double) const;
	friend Time operator*(double p, Time & t) {return t*p;}
	friend std::ostream & operator<<(std::ostream &, const Time &);
	~Time(){}
};

#endif