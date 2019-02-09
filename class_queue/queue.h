#pragma once

template <typename Item>
class Queue {
	struct List { Item item; List * next; };
	static const int Q_SIZE=5;
	List * head;
	List * end;
	int items;
	const int qsize;
	Queue(const Queue & a) : qsize(Q_SIZE) { *this=Queue(); }
	Queue & operator=(const Queue & a) { return *this; }
public:
	Queue(int qs=Q_SIZE);
	~Queue();
	bool isfull() const { return items==qsize; }
	bool isempty() const { return 0==items; }
	int count() const { return items; }
	bool add(const Item &);
	bool del(Item &);
};

template <typename Item>
Queue<Item>::Queue(int qs) : qsize(qs) {
	head=end=0;
	items=0;
}

template <typename Item>
bool Queue<Item>::add(const Item & item) {
	if (isfull())
		return false;
	List * temp=new List;
	if(!temp)
		return false;
	temp->item=item;
	temp->next=0;
	if (isempty())
		head=temp;
	else 
		end->next=temp;
	end=temp;
	++items;
	return true;
}

template <typename Item>
bool Queue<Item>::del(Item & item) {
	if (isempty())
		return false;
	item=head->item;
	List * temp=head;
	head=head->next;
	delete temp;
	--items;
	if (isempty())
		end=0;
	return true;
}

template <typename Item>
Queue<Item>::~Queue() {
	List * temp;
	while (head!=0) {
		temp=head;
		head=head->next;
		delete temp;
	}
}