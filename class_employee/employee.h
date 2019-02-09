#pragma once

#include <iostream>
#include <string>

typedef std::string str;

using std::cout;
using std::cin;
using std::endl;

class abstr_emp {
private:
	str fname;
	str lname;
	str job;
public:
	abstr_emp() {}
	abstr_emp(str const & fn, str const & ln, str const & j) : fname(fn), lname(ln), job(j) {}
	virtual void show() const {	cout << *this << "Job: " << job << endl; }
    virtual void set() {
    	cout << "Enter name: ";
	    cin >> fname;
    	cout << "Enter surname: ";
	    cin >> lname;
    	cout << "Enter job: ";
	    cin >> job;
    }
	friend std::ostream & operator<<(std::ostream & os,	abstr_emp const & e) {
        os << "Name: " << e.fname << "\nSurname: " << e.lname << endl;
    	return os;
    }
    virtual void write(std::ostream & out) const { out << fname << endl << lname << endl << job << endl; }
    virtual void read(std::istream & in) { in >> fname >> lname >> job; }
	virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp {
public:
	employee() {}
	employee(str const & fn, str const & ln, str const & j)	: abstr_emp(fn, ln, j) {}
	virtual void show() const override { cout << "Employee:\n"; abstr_emp::show(); }
	virtual void set() override { cout << "Set employee:\n";	abstr_emp::set(); }
    virtual void write(std::ostream & out) const override { out << "0\n"; abstr_emp::write(out); }
    virtual void read(std::istream & in) override { abstr_emp::read(in); }
};

class manager : virtual public abstr_emp {
private:
	int charge_;
protected:
	int charge() const { return charge_; }
	int & charge() { return charge_; }
public:
	manager() {}
	manager(str const & fn, str const & ln,	str const & j, int c = 0) : abstr_emp(fn, ln, j), charge_(c) {}
	manager(abstr_emp const & e, int c) : abstr_emp(e), charge_(c) {}
	virtual void show() const override {
	    cout << "Manager:\n";
    	abstr_emp::show();
	    cout << "Charge: " << charge_ << endl;
    }
	virtual void set() override {
	    cout << "Set manager:\n";
    	abstr_emp::set();
	    cout << "Enter chage: ";
	    cin >> charge_;
    }
    virtual void write(std::ostream & out) const override { out << "1\n"; abstr_emp::write(out); out << charge_ << endl; }
    virtual void read(std::istream & in) override { abstr_emp::read(in); in >> charge_; }
};

class fink : virtual public abstr_emp {
private:
	str reports_;
protected:
	str const & reports() const { return reports_; }
	str & reports() { return reports_; }
    virtual void wr(std::ostream & out) const { abstr_emp::write(out); }
    virtual void st() {
	    abstr_emp::set();
	    cout << "Enter reports: ";
	    cin >> reports_;
    }
public:
	fink() {}
	fink(str const & fn, str const & ln, str const & j, str const & r) : abstr_emp(fn, ln, j), reports_(r) {}
	fink(abstr_emp const & e, str const & c) : abstr_emp(e), reports_(c) {} 
	virtual void show() const override {
	    cout << "Fink:\n";
    	abstr_emp::show();
	    cout << "Reports: " << reports_ << endl;
    }
	virtual void set() override {
	    cout << "Set fink:\n";
	    abstr_emp::set();
	    cout << "Enter reports: ";
	    cin >> reports_;
    }
    virtual void write(std::ostream & out) const override { out << "2\n"; abstr_emp::write(out); out << reports_ << endl; }
    virtual void read(std::istream & in) override { abstr_emp::read(in); in >> reports_; }
};

class highfink : public manager, public fink {
public:
	highfink() {}
	highfink(str const & fn, str const & ln, str const & j, str const & r, int c) : abstr_emp(fn, ln, j), manager(fn, ln, j, c), fink(fn, ln, j, r) {}
	highfink(manager const & m, str const & r) : abstr_emp(m), manager(m), fink(m, r) {}
	highfink(fink const & m, int c) : abstr_emp(m), manager(m, c), fink(m) {}
	virtual void show() const override {
	    cout << "High ";
    	fink::show();
	    cout << "Charge: " << charge() << endl;
    }
	virtual void set() override {
	    cout << "Set high fink:\n";
	    st();
    	cout << "Enter chage: ";
	    cin >> charge();
    }
    virtual void write(std::ostream & out) const override { out << "3\n"; fink::write(out); out << charge() << endl; }
    virtual void read(std::istream & in) override { fink::read(in); in >> charge(); }
};

abstr_emp::~abstr_emp() {}
