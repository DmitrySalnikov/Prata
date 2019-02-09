#include "header.h"

double Student::average() const {
	if (((const arr_db &)(*this)).size())
		return arr_db::sum()/arr_db::size();
	else
		return 0;
}

std::ostream & Student::arr_out(std::ostream & os) const {
	int n=arr_db::size();
	if (n) {
		for (int i=0; i<n; ++i) {
			os<<((const arr_db &)(*this))[i]<<' ';
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
	is>>(std::string &)(st);
	return is;
}

std::istream & getline(std::istream & is, Student & st) {
	getline(is, (std::string &)(st));
	return is;
}

std::ostream & operator<<(std::ostream & os, Student & st) {
	std::cout<<"Marks of "<<(const std::string &)(st)<<":\n";
	return st.arr_out(os);
}