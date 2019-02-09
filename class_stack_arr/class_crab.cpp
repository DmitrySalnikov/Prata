#include <iostream>
#include "header.h"

template <template <typename T> class Thing, 
	typename U, typename V> 
class Crab {
private:
	Thing<U> s1;
	Thing<V> s2;
public:
	Crab() {}
	bool push(U a, V b) { return s1.push(a) & s2.push(b); }
	bool pop(U & a, V & b) { return s1.pop(a) & s2.pop(b); }
};

int main() {
	using std::cin;
	using std::cout;
	using std::endl;

	Crab<Stack, int, double> nebula;

	int ni;
	double nd;

	cout << "Enter int and double or 0 0 for quit\n";
	while (cin >> ni >> nd && (ni || nd)) 
		if (!nebula.push(ni, nd))
			break;

	while (nebula.pop(ni, nd)) 
		cout << ni << ' ' << nd << endl;

	return 0;
}