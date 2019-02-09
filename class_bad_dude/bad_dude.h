#pragma once

#include <string>

class Card {
private:	
	static const int SUITS = 4;
	static const char * suits[SUITS];
	static const int VALUES = 13;
	static const char * values[VALUES];
	int value;
	int suit;
public:
	Card(int v, int s) : value(v % 13), suit(s % 4) {}
	void show() const;
};

class Person {
private:
	std::string name;
	std::string surname;
protected:
	void data() const;
public:
	Person(const std::string & nm = "None", 
		const std::string & snm = "None") : name(nm), surname(snm) {}
	virtual ~Person() {}
	virtual void show() const;
};

class Gunslinger : virtual public Person {
private:
	int scratches;
	static const int MAX_DRAW = 5;
protected:
	void data() const;
public:
	Gunslinger(const std::string & nm = "None", 
		const std::string & snm = "None", int sc = 0) 
		: Person(nm, snm), scratches(sc) {}
	Gunslinger(const Person & pr, int sc = 0) 
		: Person(pr), scratches(sc) {}
	virtual void show() const;	
	void scratch() { ++scratches; }
	double draw() const;
};

class PokerPlayer : virtual public Person {
protected:
	void data() const;
public:
	PokerPlayer(const std::string & nm = "None", 
		const std::string & snm = "None") : Person(nm, snm) {}
	PokerPlayer(const Person & pr) : Person(pr) {}
	virtual void show() const;	
	Card draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer {
public:
	BadDude(const std::string & nm = "None", 
		const std::string & snm = "None", int sc = 0) 
		: Person(nm, snm), Gunslinger(nm, snm, sc), 
		PokerPlayer(nm, snm) {}
	BadDude(const Person & pr, int sc = 0) 
		: Person(pr), Gunslinger(pr, sc), PokerPlayer(pr) {}
	virtual void show() const;	
	double g_draw() const { Gunslinger::draw(); }
	Card c_draw() const { PokerPlayer::draw(); }
};