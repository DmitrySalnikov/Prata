#include "header.h"

const int pupils=3, quizzes=5;

void set(Student & st, int n) {
	std::cout<<"Enter initials of student:\n";
	getline(std::cin, st);
	std::cout<<"Enter "<<n<<" marks:\n";
	for (int i=0; i<n; ++i)
		std::cin>>st[i];
	while(std::cin.get()!='\n');
}

int main() {
	Student ada[pupils]={Student(quizzes), 
		Student(quizzes), Student(quizzes)};
	
	for (int i=0; i<pupils; ++i) 
		set(ada[i], quizzes);

	std::cout<<"\nList of student:\n";
	for (int i=0; i<pupils; ++i) 
		std::cout<<ada[i].name()<<std::endl;
	
	std::cout<<"\nResults:";
	for (int i=0; i<pupils; ++i) { 
		std::cout<<std::endl<<ada[i];
		std::cout<<"Middle: "<<ada[i].average()<<std::endl;
	}

	return 0;
}