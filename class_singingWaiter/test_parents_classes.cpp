#include "worker.h"
#include <iostream>

const int LIM=4;

int main() {
	Waiter bob("Bob Apple", 314l, 5);
	Singer bev("Beverly Hills", 522l, 3);
	Waiter w_temp;
	Singer s_temp;
	Worker * pw[LIM]={&bob, &bev, &w_temp, &s_temp};
	for (int i=2; i<LIM; ++i) 
		pw[i]->set();
	std::cout<<std::endl;
	for (int i=0; i<LIM; ++i) {
		pw[i]->show();
		std::cout<<std::endl;
	}
	return 0;
}