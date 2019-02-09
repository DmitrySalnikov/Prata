#ifndef HEADER_
#define HEADER_

#include <iostream>

class stone {
	static const int PND_PER_STN=14;
	int stones;
	double pnd;
	double pounds;
	char mod;
public:
	stone(double p=0);
	stone(int s, double p);
	~stone() {}
	void mode(char m=0);
	friend std::ostream & operator<<(std::ostream &, const stone &);
	friend std::istream & operator>>(std::istream &, stone &);
	stone operator+(const stone &) const;
	stone operator-(const stone &) const;
	stone operator*(const stone &) const;
	stone operator/(const stone &) const;
	operator double() const {return pounds;}
	bool operator<(const stone &) const;
	bool operator<=(const stone &) const;
	bool operator>(const stone &) const;
	bool operator>=(const stone &) const;
	bool operator==(const stone &) const;
	bool operator!=(const stone &) const;
	void operator=(const stone &);
};

#endif