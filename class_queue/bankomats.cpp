#include "queue.h"
#include "client.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

typedef Client Item;

bool new_client(double x) {
	return std::rand()*x/RAND_MAX<1;
}

int main() {
	const int MIN_PER_HOUR=60;
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));
	
	int qs, hours, wait_time, wait_time2, cust_min;
	long turnaways, customers, served, sum_line, sum_line2, line_wait, line_wait2, cyclelimit;
	double cl_per_hour, min_per_cl;
	Item temp;
	Queue<Item> * line, * line2;

	std::ios state(0);
	state.copyfmt(cout);
	cout<<"\nEnter maximum of queue size: ";
	while (cin>>qs) {
		line=new Queue<Item>(qs);

		cout<<"Enter hours: ";
		if (!(cin>>hours))
			break;
		cyclelimit=hours*MIN_PER_HOUR;

		
		cout<<"Enter middle amount clients per hour: ";
		if (!(cin>>cl_per_hour))
			break;
		min_per_cl=MIN_PER_HOUR/cl_per_hour;

		cust_min=turnaways=customers=served=sum_line=wait_time=line_wait=0;
		for (int cycle=0; cycle<cyclelimit; ++cycle) {
			if (new_client(min_per_cl)) 
				if (line->isfull())
					++turnaways;
				else {
					++customers;
					temp.set(cycle);
					line->add(temp);
					if (temp.hold()<=1)
						++cust_min;
				}

			if (wait_time<=0 && !(line->isempty())) {
				line->del(temp);
				wait_time=temp.hold();
				line_wait+=cycle-temp.start();
				++served;
			}

			if (wait_time>0)
				--wait_time;
			sum_line+=line->count();
		}

		cout<<"\nOne queue\n-------------------------\n";
		if (customers>0) {
			cout<<"Customers: "<<customers<<endl;
			cout<<"Served: "<<served<<endl;
			cout<<"Turnaways: "<<turnaways<<endl;
			cout<<"Middle size of queue: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.setf(ios_base::showpoint);
			cout<<(double)sum_line/cyclelimit<<endl;
			cout<<"Middle waiting time: "
				<<(double)line_wait/served<<" minutes\n";
			cout<<"Waiting less 1 min "<<(double)cust_min/hours<<" cust/hour\n\n";
		}
		else
			cout<<"No customers.\n\n";

		delete line;
		line=new Queue<Item>(qs);
		line2=new Queue<Item>(qs);
		cust_min=turnaways=customers=served=sum_line=sum_line2=wait_time=wait_time2=line_wait=line_wait2=0;
		for (int cycle=0; cycle<cyclelimit; ++cycle) {
			if (new_client(min_per_cl)) 
				if (line->isfull() && line2->isfull())
					++turnaways;
				else {
					++customers;
					temp.set(cycle);
					if (line->count()<=line2->count())	
						line->add(temp);
					else
						line2->add(temp);
					if (temp.hold()<=1)
						++cust_min;
				}

			if (wait_time<=0 && !(line->isempty())) {
				line->del(temp);
				wait_time=temp.hold();
				line_wait+=cycle-temp.start();
				++served;
			}

			if (wait_time2<=0 && !(line2->isempty())) {
				line2->del(temp);
				wait_time2=temp.hold();
				line_wait2+=cycle-temp.start();
				++served;
			}

			if (wait_time>0)
				--wait_time;

			if (wait_time2>0)
				--wait_time2;

			sum_line+=line->count();
			sum_line2+=line2->count();
		}

		cout<<"Two queues\n-------------------------\n";
		if (customers>0) {
			cout<<"Customers: "<<customers<<endl;
			cout<<"Served: "<<served<<endl;
			cout<<"Turnaways: "<<turnaways<<endl;
			cout<<"Middle size of queue: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.setf(ios_base::showpoint);
			cout<<(double)sum_line/cyclelimit<<endl;
			cout<<"Middle waiting time: "
				<<(double)line_wait/served<<" minutes\n";
			cout<<"Waiting less 1 min "<<(double)cust_min/hours<<" cust/hour\n\n";
		}
		else
			cout<<"No customers.\n\n";

		delete line;
		delete line2;
		cout<<"\nEnter maximum of queue size: ";
		cout.copyfmt(state);
	}
}