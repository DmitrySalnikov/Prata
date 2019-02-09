#include "header.h"
#include <cstring>

using std::strlen;
using std::strncpy;

DMA::DMA(const char * l, int r) {
	int n=strlen(l);
	label=new char [n+1];
	strncpy(label, l, n);
	label[n]=0;
	rating=r;
}

DMA::DMA(const DMA & d) {
	int n=strlen(d.label);
	label=new char [n+1];
	strncpy(label, d.label, n);
	label[n]=0;
	rating=d.rating;
}

DMA & DMA::operator=(const DMA & d) {
	if (this==&d)
		return *this;
	delete [] label;
	int n=strlen(d.label);
	label=new char [n+1];
	strncpy(label, d.label, n);
	label[n]=0;
	rating=d.rating;
	return *this;	
}

void DMA::view() const {
	std::cout<<"Label: "<<label<<"\nRating: "<<rating<<std::endl;
}

void BaseDMA::view() const {
	DMA::view();
}

LacksDMA::LacksDMA(const char * c, const char * l, int r) : BaseDMA(l, r) {
	int n=strlen(c);
	color=new char [n+1];
	strncpy(color, c, n);
	color[n]=0;
}

LacksDMA::LacksDMA(const char * c, const DMA & d) : BaseDMA(d) {
	int n=strlen(c);
	color=new char [n+1];
	strncpy(color, c, n);
	color[n]=0;
}

LacksDMA::LacksDMA(const LacksDMA & ld) : BaseDMA(ld) {
	int n=strlen(ld.color);
	color=new char [n+1];
	strncpy(color, ld.color, n);
	color[n]=0;	
}

LacksDMA & LacksDMA::operator=(const LacksDMA & ld) {
	if (this==&ld)
		return *this;
	BaseDMA::operator=(ld);
	delete [] color;
	int n=strlen(ld.color);
	color=new char [n+1];
	strncpy(color, ld.color, n);
	color[n]=0;	
	return *this;	
}

void LacksDMA::view() const {
	BaseDMA::view();
	std::cout<<"Color: "<<color<<std::endl;
}

HasDMA::HasDMA(const char * s, const char * l, int r) : DMA(l, r) {
	int n=strlen(s);
	style=new char [n+1];
	strncpy(style, s, n);
	style[n]=0;
}

HasDMA::HasDMA(const char * s, const DMA & d) : DMA(d) {
	int n=strlen(s);
	style=new char [n+1];
	strncpy(style, s, n);
	style[n]=0;
}

HasDMA::HasDMA(const HasDMA & d) : DMA(d) {
	int n=strlen(d.style);
	style=new char [n+1];
	strncpy(style, d.style, n);
	style[n]=0;
}

HasDMA & HasDMA::operator=(const HasDMA & d) {
	if (this==&d)
		return *this;
	DMA::operator=(d);
	delete [] style;
	int n=strlen(d.style);
	style=new char [n+1];
	strncpy(style, d.style, n);
	style[n]=0;
	return *this;	
}

void HasDMA::view() const {
	DMA::view();
	std::cout<<"Style: "<<style<<std::endl;
}