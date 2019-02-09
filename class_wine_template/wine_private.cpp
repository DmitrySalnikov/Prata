#include "wine_private.h"
#include <iostream>

void Wine::get_bottles() {
	std::cout << "Info for " << (std::string const &)(* this) << " for " << years << " years:";
	for (int i = 0; i < years; ++i) {
		std::cout << "\n\tYear: ";
		std::cin >> (pairArrInt::first())[i];

		std::cout << "\tBotles: ";
		std::cin >> (pairArrInt::second())[i];
	}
}

void Wine::show() const {
	std::cout << "Wine: " << (std::string const &)(* this) << '\n'
		<< "Year\tBottles\n";
	for (int i = 0; i < years; ++i)
		std::cout << (pairArrInt::first())[i] << '\t' << (pairArrInt::second())[i] << '\n';
}