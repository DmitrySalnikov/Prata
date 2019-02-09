#include "header.h"

Time Time::operator+(const Time & t) const {
	return Time(hours+t.hours+(minutes+t.minutes)/60, (minutes+t.minutes)%60);
}

Time Time::operator-(const Time & t) const {
	long min=minutes-t.minutes+hours-t.hours;
	return Time(min/60, min%60);
}

Time Time::operator*(double p) const {
	long min=(hours*60+minutes)*p;
	return Time(min/60, min%60);
}

std::ostream & operator<<(std::ostream & os, const Time & t) {
	os<<t.hours<<":"<<t.minutes;
	return os;
}