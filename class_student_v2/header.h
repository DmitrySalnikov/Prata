#pragma once
#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double> {
	using arr_db=std::valarray<double>;
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : std::string("Null"), arr_db() {}
	Student(const std::string & s) : std::string(s), arr_db() {}
	explicit Student(int n) : std::string("Nully"), arr_db(n) {}
	Student(const std::string & s, int n) : std::string(s), arr_db(n) {}
	Student(const std::string & s, const arr_db & a) : std::string(s), arr_db(a) {}
	Student(const char * s, const double * a, int n) : std::string(s), arr_db(a, n) {}
		//const char * != string
	~Student() {}
	double average() const;
	const std::string & name() const { return (std::string &)(*this); }
	using arr_db::operator[];
	friend std::istream & operator>>(std::istream & is, Student & st);
	friend std::istream & getline(std::istream & is, Student & st);
	friend std::ostream & operator<<(std::ostream & os, Student & st);
};