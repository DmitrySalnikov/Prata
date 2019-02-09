#pragma once
#include <iostream>
#include <string>
#include <valarray>

class Student {
	using arr_db=std::valarray<double>;
	std::string nam;
	arr_db score;
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : nam("Null"), score() {}
	Student(const std::string & s) : nam(s), score() {}
	explicit Student(int n) : nam("Nully"), score(n) {}
	Student(const std::string & s, int n) : nam(s), score(n) {}
	Student(const std::string & s, const arr_db & a) : nam(s), score(a) {}
	Student(const char * s, const double * a, int n) : nam(s), score(a, n) {}
		//const char * != string
	~Student() {}
	double average() const;
	const std::string & name() const { return nam; }
	double & operator[](int i) { return score[i]; }
	const double & operator[](int i) const { return score[i]; }
	friend std::istream & operator>>(std::istream & is, Student & st);
	friend std::istream & getline(std::istream & is, Student & st);
	friend std::ostream & operator<<(std::ostream & os, Student & st);
};