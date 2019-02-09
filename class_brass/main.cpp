#include <iostream>
#include "header.h"

const int CLIENTS=2;
const int LEN=35;

int main () {
	using std::cin;
	using std::cout;
	using std::endl;

	Acct * clients[CLIENTS];
	for (int i=0; i<CLIENTS; ++i) {
		char name[LEN], kind;
		long num;
		double bal;
		cout<<"Enter name: ";
		cin.getline(name, LEN);
		cout<<"Enter account number: ";
		cin>>num;
		cout<<"Enter initial balance: $";
		cin>>bal;
		cout<<"Choose Brass(1) or BrassPlus(2): ";
		while (cin>>kind && kind!='1' && kind!='2')
			cout<<"Enter 1 or 2: ";
		if (kind=='1') 
			clients[i]=new Brass(name, num, bal);
		else {
			double loan, rate;
			cout<<"Enter max loan: $";
			cin>>loan;
			cout<<"Enter rate: %";
			cin>>rate;
			clients[i]=new BrassPlus(name, num, bal, loan, rate/100);
		}
		while (cin.get()!='\n');
	}
	cout<<endl;

	for (int i=0; i<CLIENTS; ++i) {
		clients[i]->view();
		cout<<endl;
	}

	for (int i=0; i<CLIENTS; ++i)
		delete clients[i];

	return 0;
}