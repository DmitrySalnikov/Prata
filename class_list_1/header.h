#ifndef HEADER_
#define HEADER_

#include <string>
using std::string;

struct Customer {
	string name;
	double pay;
};

typedef Customer Item;

class List {
	Item elem;
	List * next;
public:
	List();
	void add(Item &);
	void add(const string &, double b=0);
	bool isempty() const;
	void visit(void (* pf)(Item &));
	~List();
};

#endif