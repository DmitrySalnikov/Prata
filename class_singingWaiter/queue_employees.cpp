#include "worker.h"
#include "../class_queue/queue.h"
#include <iostream>
#include <cstring>

const int SIZE=5;

bool add(Queue<Worker *> & a, char ch) {
	if (a.isfull())
		return false;

	Worker * item;
		
	switch (ch) {
		case 'w': item=new Waiter;
			break;
		case 's': item=new Singer;
			break;
		case 't': item=new SingingWaiter;
			break;
	}
	item->set();
	
	if (a.add(item))
		return true;
	else
		return false;
}


int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Queue<Worker *> queue_lolas(SIZE);
	Worker * lolas;

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
		while(cin.get()!='\n');
		add(queue_lolas, choice);
	}

	cout<<"\nYours personal:\n";
	for (int j=0; j<i; ++j) {
		cout<<endl;
		queue_lolas.del(lolas);
		lolas->show();
		delete lolas;
	}
	queue_lolas.~Queue();
	cout<<endl;

	return 0;
}