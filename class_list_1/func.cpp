#include "header.h"

	List::List() {
		next=NULL;
	}

	List::~List() {
		List * head=this;
		List * temp;
		bool flag=true;
		while(flag) {
			while (head->next) {
				temp=head;
				head=head->next;
			}
			if (head!=this) {
				delete head;
				head=this;
				temp->next=NULL;
			}
			else
				flag=false;
		}
	}

	void List::add(Item & a) {
		List * head=this;
		while (head->next!=NULL)
			head=head->next;
		head->next=new List;
		head->next->elem=a;
	}

	void List::add(const string & a, double b) {
		List * head=this;
		while (head->next!=NULL)
			head=head->next;
		head->next=new List;
		head->next->elem.name=a;
		head->next->elem.pay=b;
	}

	bool List::isempty() const {
			return this->next==NULL;
	}

	void List::visit(void (* pf)(Item &)) {
		List * head=this;
		while (head->next!=NULL) {
			head=head->next;
			pf(head->elem);
		}
	}	