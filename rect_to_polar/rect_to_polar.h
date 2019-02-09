#ifndef PROVERKA_
#define PROVERKA_

#include <iostream>
using namespace std;

const double RAD_TO_DEG=57.29577951;

struct rect {
	double x;
	double y;
};

struct polar {
	double dist;
	double angle;
};

polar & rect_to_polar(polar &, const rect &);

void show_polar(const polar &);

#endif