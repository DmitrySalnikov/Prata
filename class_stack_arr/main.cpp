#include <iostream>
#include <string>
#include <cctype>
#include "header.h"

int main() {
	using std::cout;
	using std::cin;

	Stack<std::string> st;
	char ch;
	std::string po;

	cout<<"\nA - add, P - pop, Q - exit\n";
	while (cin >> ch && std::toupper(ch) != 'Q') {
		while (cin.get() != '\n');

		switch (ch) {
			case 'a' :
			case 'A' :	cout << "Enter number to add: ";
						cin >> po;
						if (!st.isfull())
							st.push(po);
						else
							cout << "Stack is full\n";
						break;
			case 'p' :
			case 'P' :	if (!st.isempty()) {
							st.pop(po);
							cout << po << " is popped\n";
						}
						else
							cout << "Stack is empty\n";
						break;
		}

		cout<<"\nA - add, P - pop, Q - exit\n";
	}

	return 0;
}