#ifndef HEADER_
#define HEADER_

#include <ios>

class Acct {
private: 
	static const int MAX=35;
	char name[MAX];
	long num;
	double balanc;
protected:
	const char * full_name() const { return name; }
	long number() const { return num; }
	std::ios_base::fmtflags set_format() const;
public:
	Acct(const char * s="None", long n=-1, double bal=0.0);
	void deposit(double amt);
	virtual void withdraw(double amt)=0;
	double balance() const { return balanc;}
	virtual void view() const=0;
	virtual ~Acct() {} 
};

class Brass : public Acct {
public:
	Brass(const char * s="None", long an=-1, double bal=0.0) : Acct(s, an, bal) {}
	virtual void withdraw(double amt);
	virtual void view() const;
	virtual ~Brass() {}
};

class BrassPlus : public Acct {
private:
	double loan;
	double rate;
	double owes;
public:
	BrassPlus(const char *n="None", long an=-1, double bal=0.0, double ln=500, double r=0.10);
	BrassPlus(const Brass &, double ln=500, double r=0.10);
	virtual void withdraw(double amt);
	virtual void view() const;
	void reset_loan(double ln=500) { loan=ln; }
	void reset_rate(double r=0.10) { rate=r; }
	void reset_owes() { owes=0; }
};

#endif