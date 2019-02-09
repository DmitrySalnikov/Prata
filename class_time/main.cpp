#include "header.h"

int main() {
	Time work=1;
	std::cout<<"Time "<<work<<std::endl;
	work.addmin(60);
	std::cout<<"Time "<<work<<std::endl;
	std::cout<<"Time "<<work*2.33<<std::endl;
}