#pragma once

#include "io.h"
#include <cstring>

class Cd {
	char performers[50];
	char label[20];
	int selection;
	double playtime;
public:
	Cd() {}
	Cd(const char *, const char *, int, double);
	virtual ~Cd() {}
	virtual void report() const;
};

class Classic : public Cd {
	char * listing;
public:
	Classic() { listing=new char[1]; }
	Classic(const Classic &);
	Classic(const char *, const char *, const char *, int n, double x);
	virtual ~Classic() { delete[] listing; }
	Classic & operator=(const Classic &);
	virtual void report() const;
};