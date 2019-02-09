#include "header.h"

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	Port three_sevens("777", "tawny", 25);
	VintagePort colheita("Colheita", 10, "Best of the best", 1975);
	
	while(cin) {
		cout<<endl;
		three_sevens.view();
		cout<<endl;
		colheita.view();
		cout<<endl;
		int select;
		cout<<"Select portwein(1 or 2): ";
		cin>>select;
		int count;
		switch (select) {
			case 1: cout<<"How bottles?\n";
					cin>>count;
					three_sevens-=count;
					break;
			case 2: cout<<"How bottles?\n";
					cin>>count;
					colheita-=count;
					break;
		}
		if (cin) {
			char answer;
			cout<<"Anything else?\n";
			cin>>answer;
			if ((answer!='y') && (answer!='Y'))
				break;
		}
	}
	cout<<"Good bye!\n";
	return 0;
}