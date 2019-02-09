#include <cmath>
#include "rect_to_polar.h"

polar & rect_to_polar(polar & pc, const rect & rc) {
	pc.dist=sqrt(pow(rc.x, 2)+pow(rc.y, 2));
	pc.angle=atan2(rc.y, rc.x);
	return pc;
}

void show_polar(const polar & pc) {
	cout<<pc.dist<<" "<<pc.angle*RAD_TO_DEG<<endl;
}