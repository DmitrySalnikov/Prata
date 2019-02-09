#include <iostream>
#include "header.h"

void ol(Item & a) {
	std::cout<<a.name<<" "<<a.pay<<std::endl;
}

int main() {
	List a;
	if (!a.isempty())	
		a.add("hjgjh", 98);
	Item b={"cvx", 12};
	a.add(b);
	a.add("ghj", 8);
	if (!a.isempty())	
		a.visit(ol);
}				