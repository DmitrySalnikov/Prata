#include "header.h"

Cd::Cd(const char * per, const char * l, int n, double x) {
	std::strncpy(performers, per, 49);
	performers[49]=0;
	std::strncpy(label, l, 19);
	label[19]=0;
	selection=n;
	playtime=x;
}

void Cd::report() const {
	cout<<"Performers: "<<performers
		<<"\nLabel: "<<label
		<<"\nSelection: "<<selection
		<<"\nPlaytime: "<<playtime<<endl;
}

Classic::Classic(const Classic & cl) : Cd(cl) {
	int n=std::strlen(cl.listing);
	listing=new char[n+1];
	std::strncpy(listing, cl.listing, n);
	listing[n]=0;
}

Classic::Classic(const char * list, const char * per, 
	const char * l, int n, double x) : Cd(per, l, n, x) {
	int m=std::strlen(list);
	listing=new char[m+1];
	std::strncpy(listing, list, m);
	listing[m]=0;	
}

Classic & Classic::operator=(const Classic & cl) {
	if (this==&cl)
		return *this;
	(*this).Cd::operator=(cl);
	delete[] listing;
	int n=std::strlen(cl.listing);
	listing=new char[n+1];
	std::strncpy(listing, cl.listing, n);
	listing[n]=0;	
	return *this;
}

void Classic::report() const {
	cout<<"Listing: "<<listing<<endl;
	(*this).Cd::report();
}