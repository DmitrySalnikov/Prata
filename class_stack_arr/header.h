#pragma once

template <typename T>
class Stack {
	static const int MAX=10;
	T * items;
	int max;
	int top;
public:
	Stack(int n=MAX);
	Stack(const Stack &);
	~Stack();
	bool isempty() const { return top==0; }
	bool isfull() const { return top==max; }
	bool push(const T &);
	bool pop(T &);
	Stack & operator=(const Stack &);
};

template <typename T>
Stack<T>::Stack(int n) : max(n) {
	items=new T [n];
	top=0;
}

template <typename T>
Stack<T>::Stack(const Stack & st) : max(st.max) {
	top=st.top;
	items=new T [max];
	for (int i=0; i<top; ++i)
		items[i]=st.items[i];
}

template <typename T>
Stack<T>::~Stack() {
	delete [] items;
}

template <typename T>
bool Stack<T>::push(const T & item) {
	if (isfull())
		return false;
	items[top]=item;
	++top;
	return true;
}

template <typename T>
bool Stack<T>::pop(T & item) {
	if (isempty())
		return false;
	item=items[top-1];
	--top;
	return true;
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack & st) {
	if (this==&st)
		return *this;
	max=st.max;
	top=st.top;
	delete [] items;
	items=new T [max];
	for (int i=0; i<top; ++i)
		items[i]=st.items[i];
	return *this;
}