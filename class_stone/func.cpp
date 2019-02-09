#include "header.h"

stone::stone(double p) {
	pounds=p;
	stones=int(p)/PND_PER_STN;
	pnd =p-stones*PND_PER_STN;
	mod='p';
}

stone::stone(int s, double p) {
	pounds=s*PND_PER_STN+p;
	*this=stone(pounds);
	mod='s';
}

void stone::mode(char m) {
	std::cout<<mod<<std::endl;
	if ('p'==m)
		mod='p';
	else if ('s'==m)
		mod='s';
	else if ('p'==mod)
		mod='s';
	else
		mod='p';
}

std::ostream & operator<<(std::ostream & os, const stone & st) {
	if (st.mod!='s') { 
		os<<st.pounds<<" pounds";
		if ('p'!=st.mod)
			std::cerr<<"Error mode, mode installed as \"pounds\"\n";
	}
	else 
		os<<st.stones<<" stones and "<<st.pnd<<" pounds";
	return os;
}
	
std::istream & operator>>(std::istream & is, stone & st) {
	if (st.mod!='s') { 
		if ('p'!=st.mod)
			std::cerr<<"Error mode, mode installed as \"pounds\"\n";
		std::cout<<"Enter pounds :";
		is>>st.pounds;
		char m=st.mod;
		st=stone(st.pounds);
		if (('p'==m) || ('s'==m))
			st.mod=m;
		else {
			std::cerr<<"Error mode, mode installed as \"pounds\"\n";
			st.mod='p';
		}
	}
	else { 
		std::cout<<"Enter stones: ";
		is>>st.stones;
		std::cout<<"Enter pounds: ";
		is>>st.pnd;
		char m=st.mod;
		st=stone(st.stones, st.pnd);
		if (('p'==m) || ('s'==m))
			st.mod=m;
		else {
			std::cerr<<"Error mode, mode installed as \"pounds\"\n";
			st.mod='p';
		}
	}
	return is;
}

stone stone::operator+(const stone & st) const {
	return stone(pounds+st.pounds);
}

stone stone::operator-(const stone & st) const {
	return stone(pounds-st.pounds);
}

stone stone::operator*(const stone & st) const {
	return stone(pounds*st.pounds);
}

stone stone::operator/(const stone & st) const {
	return stone(pounds/st.pounds);
}

bool stone::operator<(const stone & st) const {
	if (pounds<st.pounds)
		return true;
	else
		return false;
}

bool stone::operator<=(const stone & st) const {
	if (pounds<=st.pounds)
		return true;
	else
		return false;
}

bool stone::operator>(const stone & st) const {
	if (pounds>st.pounds)
		return true;
	else
		return false;
}

bool stone::operator>=(const stone & st) const {
	if (pounds>=st.pounds)
		return true;
	else
		return false;
}

bool stone::operator==(const stone & st) const {
	if (pounds==st.pounds)
		return true;
	else
		return false;
}

bool stone::operator!=(const stone & st) const {
	if (pounds!=st.pounds)
		return true;
	else
		return false;
}

void stone::operator=(const stone & st) {
	stones=st.stones;
	pounds=st.pounds;
	pnd=st.pnd;
}