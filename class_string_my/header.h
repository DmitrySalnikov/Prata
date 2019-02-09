#ifndef HEADER_
#define HEADER_

#include <iostream>

class String {
	char * str;
	int len;
	static int num;
	static const int CINLIM=80;
public:
	String(const char * a="");
	String(const String &);
	~String();
	int size() const { return len; }
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i) { return str[i]; }
	const char & operator[](int i) const { return str[i]; }
	friend bool operator>(const String &, const String &);
	friend bool operator<(const String &, const String &);
	friend bool operator==(const String &, const String &);
	friend std::ostream & operator<<(std::ostream &, const String &);
	friend std::istream & operator>>(std::istream &, String &);	
	static int all() { return num; }
	friend const String operator+(const String &, const String &);
	const String strlow() const;
	const String strup() const;
	const int has(char ch) const;
};

#endif