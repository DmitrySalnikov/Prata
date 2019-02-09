#include "header.h"

void bravo(const Cd & disk) {
	disk.report();
}

int main() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2("Piano Sonata in B flat, Fantasia in C", 
		"Alfred Brendel", "Phillips", 2, 57.17);
	Cd * pcd=&c1;

	cout<<"\nUsing object directly:\n";
	c1.report();
	c2.report();

	cout<<"\nUsing TYPE Cd * pointer to objects:\n";
	pcd->report();
	pcd=&c2;
	pcd->report();

	cout<<"\nCalling a function:\n";
	bravo(c1);
	bravo(c2);

	cout<<"\nTesting assigment:\n";
	Classic copy;
	copy=c2;
	copy.report();

	return 0;
}