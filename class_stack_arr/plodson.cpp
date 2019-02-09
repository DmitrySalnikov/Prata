#include <iostream>
#include <ctime>
#include <cstdlib>
#include "header.h"

const int NUM = 10;

int main() {
	using std::cout;
	using std::cin;

	typedef const char * ccp;

	std::srand(std::time(0));

	cout << "Size of stack: ";
	int size = 0;
	cin >> size;

	Stack<ccp> st(size);
	
	ccp in[NUM] = {
		"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"
	};

	ccp out[NUM];

	int pin = 0;
	int pout = 0;

	while (pout < NUM) {
		if (st.isempty())
			st.push(in[pin++]);
		else if (st.isfull())
			st.pop(out[pout++]);
		else if (std::rand() % 2 && pin < NUM)
			st.push(in[pin++]);
		else
			st.pop(out[pout++]);
	}

	for (int i = 0; i < NUM; ++i)
		cout << out[i] << ' ';
	cout << std::endl;

	return 0;
}