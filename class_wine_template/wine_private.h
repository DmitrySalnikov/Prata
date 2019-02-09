#pragma once

#include "pair.h"
#include <string>
#include <valarray>

class Wine : private std::string, 
	private Pair< std::valarray<int>, std::valarray<int> > {
private:
	typedef std::valarray<int> arrInt;
	typedef Pair<arrInt, arrInt> pairArrInt;
	int years;
public:
	Wine() {}
	Wine(const char * l, int y, const int yr[], const int bot[]) :
		std::string(l), years(y), pairArrInt(arrInt(yr, y), arrInt(bot, y)) {}
	Wine(const char * l, int y) : std::string(l), years(y), 
		pairArrInt(arrInt(y), arrInt(y)) {}
	void get_bottles();
	std::string const & label() const { return (std::string const &)(*this); }
	std::string & label() { return (std::string &)(*this); }
	int sum() const { return (pairArrInt::second()).sum(); }
	void show() const;
};