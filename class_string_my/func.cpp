#include "header.h"
#include <cstring>
#include <cctype>

int String::num=0;

String::String(const char * a) {
	len=std::strlen(a); 
	str=new char [len+1]; 
	std::strcpy(str, a);
	++num;
}
	
String::String(const String & st) {
	len=st.len;
	str=new char [len+1];
	std::strcpy(str, st.str);
	++num;
}

String::~String() {
	--num;
	delete [] str;
}

String & String::operator=(const String & st) {
	if (this==&st)
		return *this;
	delete [] str;
	len=st.len;
	str=new char [len+1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char * st) {
	delete [] str;
	len=std::strlen(st);
	str=new char [len+1];
	std::strcpy(str, st);
	return *this;
}

bool operator>(const String & st1, const String & st2) {
	return std::strcmp(st1.str, st2.str)>0;
}

bool operator<(const String & st1, const String & st2) {
	return st2>st1;
}

bool operator==(const String & st1, const String & st2) {
	return 0==std::strcmp(st1.str, st2.str);
}

std::ostream & operator<<(std::ostream & os, const String & st) {
	os<<st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM-1).get();
	temp[String::CINLIM-1]=0;
	if (is)
		st=temp;
	return is;
}

const String operator+(const String & str1, const String & str2) {
	String temp;
	temp.len=str1.len+str2.len;
	delete [] temp.str;
	temp.str=new char [temp.len+1];
	std::strcpy(temp.str, str1.str);
	std::strcat(temp.str, str2.str);
	return temp;
}

const String String::strlow() const {
	String temp;
	temp.len=len;
	delete [] temp.str;
	temp.str=new char [len+1];
	for (int i=0; i<=len; ++i) {
		temp[i]=std::tolower(str[i]);
	}
	return temp;
}

const String String::strup() const {
	String temp;
	temp.len=len;
	delete [] temp.str;
	temp.str=new char [len+1];
	for (int i=0; i<=len; ++i) {
		temp[i]=std::toupper(str[i]);
	}
	return temp;
}

const int String::has(char ch) const {
	int res=0;
	for (int i=0; i<len; ++i)
		if (std::tolower(str[i])==ch || std::toupper(str[i])==ch)
			++res;
	return res;
}