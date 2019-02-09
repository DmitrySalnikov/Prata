#pragma once

#include "pair.h"
#include <string>
#include <valarray>

class Wine {
private:
	typedef std::valarray<int> arrInt;
	typedef Pair<arrInt, arrInt> pairArrInt;
	std::string name;
	int years;
	pairArrInt info;
public:
	Wine() {}
	Wine(const char * l, int y, const int yr[], const int bot[]) :
		name(l), years(y), info(arrInt(yr, years), arrInt(bot, years)) {}
	Wine(const char * l, int y) : name(l), years(y), info(arrInt(years), arrInt(years)) {}
	void get_bottles();
	std::string const & label() const { return name; }
	std::string & label() { return name; }
	int sum() const { return (info.second()).sum(); }
	void show() const;
};