#include "bad_dude.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void Card::show() const {
	cout << values[value] << '-' << suits[suit] << endl;
}

const char * Card::suits[SUITS] = 
	{"Heart", "Diamond", "Spade", "Club"};

const char * Card::values[VALUES] =
		{"2", "3", "4", "5", "6", "7", "8", "9", "10", 
		"Jack", "Queen", "King", "Ace"};


void Person::data() const {
	cout << "Name: " << name << endl
		<< "Surname: " << surname << endl;	
}

void Person::show() const {
	cout << "Person:\n";
	data();
}


void Gunslinger::data() const {
	Person::data();
	cout << "Scratches: " << scratches << endl;
}

void Gunslinger::show() const {
	cout << "Gunslinger:\n";
	data();
}

double Gunslinger::draw() const {
	int dr = std::rand() % MAX_DRAW;
	double sec = std::rand() % 60;
	return dr + sec / 100;
}


void PokerPlayer::data() const {
	Person::data();
}

void PokerPlayer::show() const {
	cout << "Poker player:\n";
	data();
}

Card PokerPlayer::draw() const {
	return Card(std::rand() % 13, std::rand() % 4);
}


void BadDude::show() const {
	cout << "Bad dude:\n";
	Gunslinger::data();
}