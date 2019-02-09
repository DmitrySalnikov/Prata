#include "header.h"

int main() {
	stone a(11);
	stone cargo[6];
	for (int i=0; i<6; ++i)
		std::cin>>cargo[i];
	stone max=cargo[0];
	stone min=cargo[0];
	int sum=0;
	for (int i=1; i<6; ++i) {
		if (cargo[i]<min)
			min=cargo[i];
		else if (cargo[i]>max)
			max=cargo[i];
		if (cargo[i]>=a)
			++sum;
	}
	if (cargo[0]>=stone(11))
		++sum;
	std::cout<<max<<std::endl<<min<<std::endl<<sum<<std::endl;
}