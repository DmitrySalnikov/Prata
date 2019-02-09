#include "header.h"

/*
BaseDMA a;
LacksDMA b;
HasDMA c;
*/

const int CLIENTS=4;
const int LEN=35;

int main () {
	using std::cin;
	using std::cout;
	using std::endl;

	DMA * clients[CLIENTS];
	for (int i=0; i<CLIENTS; ++i) {
		char label[LEN], kind;
		int rating;
		cout<<"Enter label: ";
		cin.getline(label, LEN);
		cout<<"Enter rating: ";
		cin>>rating;
		cout<<"Choose BaseDMA(1), LacksDMA(2) or HasDMA(3): ";
		while (cin>>kind && kind!='1' && kind!='2' && kind!='3')
			cout<<"Enter 1, 2 or 3: ";
		if (kind=='1') 
			clients[i]=new BaseDMA(label, rating);
		else if (kind=='2') {
			char color[LEN];
			cout<<"Enter color: ";
			cin>>color;
			clients[i]=new LacksDMA(color, label, rating);
		}
		else {
			char style[LEN];
			cout<<"Enter color: ";
			cin>>style;
			clients[i]=new HasDMA(style, label, rating);
		}
		while (cin.get()!='\n');
	}
	cout<<endl;

	for (int i=0; i<CLIENTS; ++i) {
		clients[i]->view();
		cout<<endl;
	}

	for (int i=0; i<CLIENTS; ++i)
		delete clients[i];

	return 0;
}