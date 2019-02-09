#include "worker.h"
#include <iostream>
#include <cstring>

const int SIZE=5;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Worker * lolas[SIZE];

	int i;
	for (i=0; i<SIZE; ++i) {
		char choice;
		cout<<"Enter category of staff:\n"
			"w: waiter, s: singer, t: singing waiter, q: exit\n";
		cin>>choice;
		while (!strchr("wstq", choice)) {
			cout<<"Please, w, s, t or q:\n";
			cin>>choice;
		}
		if (choice=='q')
			break;
		switch (choice) {
			case 'w': lolas[i]=new Waiter;
				break;
			case 's': lolas[i]=new Singer;
				break;
			case 't': lolas[i]=new SingingWaiter;
				break;
		}
		while(cin.get()!='\n');
		lolas[i]->set();
	}

	cout<<"Yours personal:\n";
	for (int j=0; j<i; ++j) {
		cout<<endl;
		lolas[j]->show();
		delete lolas[j];
	}
	cout<<endl;

	return 0;
}