#include "Complex.h"

int main() {
	Complex a(3.0, 4.0);
	Complex c;
	cout<<"Enter complex number: \n";
	while (cin>>c) 
		cout<<c<<endl
			<<~c<<endl
			<<a<<endl
			<<a+c<<endl
			<<a-c<<endl
			<<a*c<<endl
			<<2*c<<endl
			<<"Enter next complex number: \n";
    
    return 0;
}
