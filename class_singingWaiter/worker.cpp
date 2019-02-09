#include "worker.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


void Worker::data() const {
	cout<<"Name: "<<name<<endl
		<<"Id: "<<id<<endl;
}

void Worker::get() {
	getline(cin, name);
	cout<<"Enter id: ";
	cin>>id;
	while(cin.get()!='\n');
}


void Waiter::get() {
	cout<<"Enter panache: ";
	cin>>panache;
	while(cin.get()!='\n');
}

void Waiter::set() {
	cout<<"Enter initials of waiter: ";
	Worker::get();
	get();
}

void Waiter::data() const {
	cout<<"Panache: "<<panache<<endl;
}

void Waiter::show() const {
	cout<<"Category: Waiter\n";
	Worker::data();
	data();
}


const char * Singer::pv[VTYPES]={"other", "alto", "contralto", 
	"soprano", "bass", "baritone", "tenor"};

void Singer::get() {
	cout<<"Enter voice:\n";
	for (int i=0; i<VTYPES; ++i) {
		cout<<i<<": "<<pv[i]<<", ";
		if (i%4==3)
			cout<<endl;
	}
	if (VTYPES%4!=0)
		cout<<endl;
	cin>>voice;
	while (cin.get()!='\n');
}

void Singer::set() {
	cout<<"Enter initials of singer: ";
	Worker::get();
	get();	
}

void Singer::data() const {
	cout<<"Voice: "<<pv[voice]<<endl;
}

void Singer::show() const {
	cout<<"Category: Singer\n";
	Worker::data();
	data();
}


void SingingWaiter::data() const{
	Singer::data();
	Waiter::data();
}

void SingingWaiter::get() {
	Waiter::get();
	Singer::get();
}

void SingingWaiter::set() {
	cout<<"Enter initials of singing waiter: ";
	Worker::get();
	get();
}

void SingingWaiter::show() const {
	cout<<"Category: Singing waiter\n";
	Worker::data();
	data();
}