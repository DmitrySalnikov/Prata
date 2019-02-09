#include "header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using VECTOR::Vector;
using std::cout;
using std::endl;
using std::cin;

bool path(std::istream & in=std::cin, std::ostream & out=std::cout, std::ostream & out2=std::cout);

int main() {
	srand(time(0));
	std::ofstream fout;
	fout.open("out.txt");
	if (!fout) {std::cerr<<"Error opening out.txt\n";}
	std::ifstream fin;
	fin.open("in.txt");
	if (!fin) {std::cerr<<"Error opening in.txt\n";}

	while (path(fin, fout));

	do 
		cout<<"Distance, step length: ";
	while (path(cin, fout));
}

bool path(std::istream & in, std::ostream & out, std::ostream & out2) {
	double dist;
	if (!(in>>dist))
		return false;
	double len;
	if (!(in>>len))
		return false;

	Vector result;
	Vector step;
	unsigned long int steps=0;
	double direct;

	while (result.dist()<dist) {
		direct=rand()%179;
		step.set(len, result.course()+89-direct);
		result+=step;
		++steps;
	}

	out<<"Distance: "<<dist<<endl
		<<"step length: "<<len<<endl;
	out<<"You have passed "<<steps<<" steps.\n";
	out<<"Middle distance per step: "<<result.dist()/steps<<endl<<endl;
	if (out2!=out) {
	out2<<"Distance: "<<dist<<endl
		<<"step length: "<<len<<endl;
	out2<<"You have passed "<<steps<<" steps.\n";
	out2<<"Middle distance per step: "<<result.dist()/steps<<endl<<endl;
	}
	return true;
}