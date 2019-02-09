#pragma once

#include <iostream>

class Port {
	char * brand;
	char * style;	//tawny, ruby, vintage
	int bottles;
public:
	Port(const char * br="none", const char * st="none", int b=0);
	Port(const Port & p);
	virtual ~Port() { delete [] brand; delete [] style; }
	Port & operator=(const Port & p);
	Port & operator+=(int b);
	Port & operator-=(int b);
	int bottle_count() const { return bottles; }
	virtual void view() const;
	friend std::ostream & operator<<(std::ostream & os, const Port & p);
};

class VintagePort : public Port {
	char * nick;
	int year;
public:
	VintagePort();
	VintagePort(const char * br, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);
	virtual ~VintagePort() { delete [] nick; }
	VintagePort & operator=(const VintagePort & vp);
	virtual void view() const;
	friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);
};