#pragma once
#include <string>

class Worker {
private:
	std::string name;
	long id;
protected:
	virtual void data() const;
	virtual void get();
public:
	Worker() : name("Null"), id(0l) {}
	Worker(const std::string & s, long n) : name(s), id(n) {}
	virtual ~Worker() {}
	virtual void set() = 0;
	virtual void show() const = 0;
};

class Waiter : virtual public Worker {
private:
	int panache;
protected:
	void data() const;
	void get();
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const std::string & s, long n, int p=0) :
		Worker(s, n), panache(p) {}
	Waiter(const Worker & w, int p=0) : Worker(w), panache(p) {}
	void set();
	void show() const;
};

class Singer : public virtual Worker {
protected:
	enum{other, alto, contralto, soprano, bass, baritone, tenor};
	static const int VTYPES=7;
	void data() const;
	void get();
private:
	static const char * pv[VTYPES];
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v=other) :
		Worker(s, n), voice(v) {}
	Singer(const Worker & w, int v=other) :
		Worker(w), voice(v) {}
	void set();
	void show() const;
};

class SingingWaiter : public Singer, public Waiter {
protected:
	void data() const;
	void get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string & s, long n, int p=0, int v=other) :
		Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	SingingWaiter(const Worker & w, int p=0, int v=other) :
		Worker(w), Waiter(w, p), Singer(w, v) {}
	SingingWaiter(const Waiter & w, int v=other) :
		Worker(w), Waiter(w), Singer(w, v) {}
	SingingWaiter(const Singer & w, int p=0) :
		Worker(w), Waiter(w, p), Singer(w) {}
	void set();
	void show() const;
};