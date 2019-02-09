#include "wine_private.h"
#include <iostream>

int main() {
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "\nLabel of wine: ";
	char lab[50] = {};
	cin.getline(lab, 50);

	cout << "Тumber of harvests: ";
	int years = 0;
	cin >> years;

	Wine holding(lab, years);
	cout << endl;
	holding.get_bottles();
	cout << endl;
	holding.show();

	const int YEARS = 3;
	int y[YEARS] = { 1993, 1995, 1998 };
	int b[YEARS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YEARS, y, b);
	cout << endl;
	more.show();

	cout << "Total number of bottles: " << more.label()
		<< ": " << more.sum() << endl << endl;

	return 0;
}