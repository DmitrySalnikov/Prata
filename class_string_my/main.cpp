#include "header.h"
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int main() {
/*
	const int n=5;
	String name;
	cout<<"Your name: ";
	while(!(cin>>name)) {
		cin.clear();
		while (cin.get()!='\n');
		cout<<"Your name: ";
	}

	String say[n];
	int i;
	cout<<name<<", enter "<<n<<" sayings:\n";
	for (i=0; i<n; ++i) {
		cin>>say[i];
		if (!cin || 0==say[i][0])
			break;
	}
	cout<<"You are enter "<<i<<" says\n";

	int max=0;
	int first=0;
	for (int j=1; j<i; ++j) {
		if (say[j].size()>say[max].size())
			max=j;
		if (say[j]<say[first])
			first=j;
	}
	cout<<"Longest say is say №"<<max+1<<":\n"<<say[max]<<endl;
	cout<<"First say alphabetically is say №"<<first+1<<":\n"<<say[first]<<endl;
	cout<<"This program is used "<<String::all()<<" objects \"String\"\n";
*/	
	
	String s1(" and I am a C++ student.");
	String s2="Please enter your name: ";
	String s3;
	cout<<s2;
	cin>>s3;
	s2="My name is "+s3;
	cout<<s2<<endl;
	s2=s2+s1;
	s2=s2.strup();
	cout<<"The string\n"<<s2<<"\ncontains "<<s2.has('a')
	 <<" 'A' characters in it.\n";
	s1="red";
	String rgb[3]={s1, String("green"), String("blue")};
	cout<<"Enter color: ";
	String ans;
	bool suc=false;
	while (cin>>ans) {
			ans=ans.strlow();
			for (int i=0; i<3; ++i) {
				if (ans==rgb[i]) {
					cout<<"That's right!\n";
					suc=true;
					break;
				}
			}
			if (suc)
				break;
			else 
				cout<<"Try again: ";
	}
}