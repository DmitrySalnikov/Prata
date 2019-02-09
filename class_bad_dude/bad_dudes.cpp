#include "bad_dude.h"
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>

const int SIZE=5;

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	using std::string;

	std::srand(std::time(0));

	Person * lolas[SIZE];

	int i;
	for (i=0; i<SIZE; ++i) {
		char choice;
		cout<<"\nEnter category of person:\n"
			"g: gunslinger, p: poker player, b: bad dude, q: exit\n";
		cin>>choice;
		while (!strchr("gpbq", choice)) {
			cout<<"Please, g, p, b or q:\n";
			cin>>choice;
		}
		if (choice=='q')
			break;
		string name;
		cout << "Enter name: ";
		cin >> name;
		string surname;
		cout << "Enter surname: ";
		cin >> surname;
		int scratces;
		switch (choice) {
			case 'g': cout << "Enter number of scratces: ";
				cin >> scratces;
				lolas[i]=new Gunslinger(name, surname, scratces);
				break;
			case 'p': lolas[i]=new PokerPlayer(name, surname);
				break;
			case 'b': cout << "Enter number of scratces: ";
				cin >> scratces;
				lolas[i]=new BadDude(name, surname, scratces);
				break;
		}
	}

	if (i)
		cout<<"\nPersons:\n";
	for (int j=0; j<i; ++j) {
		cout<<endl;
		lolas[j]->show();
		delete lolas[j];
	}
	cout<<endl;

	cout << "Ooh no, it's a new BAD DUDE!\n\n";
	BadDude dmitry("Dmitry", "Salnikov", 3);
	dmitry.show();
	cout << "His card: ";
	dmitry.c_draw().show();
	cout << "His draw: " << dmitry.g_draw();
	cout << "\n\nOoh no, he add scratch!\n\n";
	dmitry.scratch();
	dmitry.show();
	cout << endl;

	return 0;
}