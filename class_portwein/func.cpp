#include "header.h"
#include <cstring>

using std::strlen;
using std::strncpy;

char * cp(const char * nick) {
	int n=strlen(nick);
	char * name=new char [n+1];
	strncpy(name, nick, n);
	name[n]=0;
	return name;
}

Port::Port(const char * br, const char * st, int b) {
	brand=cp(br);
	style=cp(st);
	bottles=b;
}

Port::Port(const Port & p) {
	brand=cp(p.brand);
	style=cp(p.style);
	bottles=p.bottles;
}

Port & Port::operator=(const Port & p) {
	if (this==&p)
		return *this;
	delete [] brand;
	brand=cp(p.brand);
	delete [] style;
	style=cp(p.style);
	bottles=p.bottles;
	return *this;
}

Port & Port::operator+=(int b) {
	bottles+=b;
	return *this;
}

Port & Port::operator-=(int b) {
	if (bottles>=b) {
		bottles-=b;
		return *this;
	}
	else {
		std::cout<<"Not enough bottles\n";
		return *this;
	}
}

void Port::view() const {
	std::cout<<"Brand: "<<brand
		<<"\nStyle: "<<style
		<<"\nBottles: "<<bottles<<std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p) {
	os<<p.brand<<", "<<p.style<<", "<<p.bottles;
	return os;
}

VintagePort::VintagePort() : Port("none", "vintage", 0) {
	nick=cp("none");
	year=0;
}

VintagePort::VintagePort(const char * br, int b, 
	const char * nn, int y) : Port(br, "vintage", b) {
	nick=cp(nn);
	year=y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp) {
	nick=cp(vp.nick);
	year=vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp) {
	if (this==&vp)
		return *this;
	Port::operator=(vp);
	delete [] nick;
	nick=cp(vp.nick);
	year=vp.year;
}

void VintagePort::view() const {
	Port::view();
	std::cout<<"Nickname: "<<nick
		<<"\nYear: "<<year<<std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp) {
	os<<Port(vp)<<", "<<vp.nick<<", "<<vp.year;
	return os;
}