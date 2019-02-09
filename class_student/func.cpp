#include "header.h"

double Student::average() const {
	if (score.size())
		return score.sum()/score.size();
	else
		return 0;
}

std::ostream & Student::arr_out(std::ostream & os) const {
	int n=score.size();
	if (n) {
		for (int i=0; i<n; ++i) {
			os<<score[i]<<' ';
			if (i%5==4)
				os<<std::endl;
		}
		if (n%5)
			os<<std::endl;
	}
	else
		os<<"Empty array\n";
	return os;
}

std::istream & operator>>(std::istream & is, Student & st) {
	is>>st.nam;
	return is;
}

std::istream & getline(std::istream & is, Student & st) {
	getline(is, st.nam);
	return is;
}

std::ostream & operator<<(std::ostream & os, Student & st) {
	std::cout<<"Marks of "<<st.nam<<":\n";
	return st.arr_out(os);
}