#include "rect_to_polar.h"

int main() {
	rect rc;
	polar pc;
	cout<<"x, y: ";
	while (cin>>rc.x>>rc.y) {
		rect_to_polar(pc, rc);
		show_polar(pc);
		cout<<"x, y: ";
	}
}