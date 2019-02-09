#include "header.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::ios_base;
using std::endl;

ios_base::fmtflags Acct::set_format() const {
	ios_base::fmtflags state=
		cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout.precision(2);
	return state;
}

Acct::Acct(const char * s, long n, double bal) {
	std::strncpy(name, s, MAX-1);
	name[MAX-1]='\0';
	num=n;
	balanc=bal;
}

void Acct::deposit(double amt) {
	if (amt<=0)
		cout<<"Incorrect deposit\n";
	else
		balanc+=amt;
}

void Acct::withdraw(double amt) {
	balanc-=amt;
}

void Acct::view() const {
	ios_base::fmtflags state=set_format();
	cout<<"Name: "<<name<<endl;
	cout<<"Account number: "<<num<<endl;
	cout<<"Balance: $"<<balanc<<endl;
	cout.setf(state);
}

void Brass::withdraw(double amt) {
	if (amt<=0)
		cout<<"Incorrect sum withdraw\n";
	else if (amt>balance())
		cout<<"Not enough money\n";
	else
		Acct::withdraw(amt);
}

void Brass::view() const {
	Acct::view();
}

BrassPlus::BrassPlus(const char * s, long an, double bal, 
	double ln, double r) : Acct(s, an, bal) {
	loan=ln;
	rate=r;
	owes=0.0;
}

BrassPlus::BrassPlus(const Brass & br, double ln, 
	double r) : Acct(br), loan(ln), rate(r), owes(0.0) {}

void BrassPlus::withdraw(double amt) {
	if (amt<=0) {
		cout<<"Incorrect sum withdraw\n";
		return;
	}
	double bal=balance();
	if (amt<=bal)
		Acct::withdraw(amt);
	else if (amt > bal+loan-owes)
		cout<<"Loan amount exceeded\n";
	else {
		double advance=amt-bal;
		owes+=advance;
		ios_base::fmtflags state=set_format();
		cout<<"Bank advance: $"<<advance<<endl;
		cout<<"Tax: $"<<advance*rate<<endl;
		cout.setf(state);
		deposit(advance);
		Acct::withdraw(amt);
	}
}

void BrassPlus::view() const {
	Acct::view();
	ios_base::fmtflags state=set_format();
	cout<<"Max loan: $"<<loan<<endl;
	cout<<"Tax: "<<rate*100<<"%\n";
	cout<<"Bank owes: $"<<owes<<endl;
	cout.setf(state);
}