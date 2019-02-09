#include "wine.h"
#include <iostream>

void Wine::get_bottles() {
	std::cout << "Info for " << name << " for " << years << " years:";
	for (int i = 0; i < years; ++i) {
		std::cout << "\n\tYear: ";
		std::cin >> (info.first())[i];

		std::cout << "\tBottles: ";
		std::cin >> (info.second())[i];
	}
}

void Wine::show() const {
	std::cout << "Wine: " << name << '\n'
		<< "Year\tBottles\n";
	for (int i = 0; i < years; ++i)
		std::cout << (info.first())[i] << '\t' << (info.second())[i] << '\n';
}