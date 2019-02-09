#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <random>
#include <limits>
#include <iomanip>
#include <fstream>
#include <sstream>

namespace my {
    std::default_random_engine g;
    std::uniform_int_distribution<int> u(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

std::pair<double, double> mean_int(int len, int iter = 1) {
    using namespace my;

    double l_sec = 0.;
    double v_sec = 0.;
    std::list<int> l(len);
    std::list<int> tmp(len);
    std::vector<int> v(len);
    for (int i = 0; i < iter; ++i) {
        for (auto & x : l) x = u(g);
        std::copy(l.begin(), l.end(), tmp.begin());

        auto start = clock();
        tmp.sort();
        l_sec += (clock() - start) / (double)CLOCKS_PER_SEC;

        start = clock();
        std::copy(l.begin(), l.end(), v.begin());
        std::sort(v.begin(), v.end());
        std::copy(v.begin(), v.end(), l.begin());
        v_sec += (clock() - start) / (double)CLOCKS_PER_SEC;
    }

    return {l_sec / iter, v_sec / iter};
}

int main(int argc, char ** argv) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::clock;

    std::ofstream fout("vector_vs_list.txt", std::ios_base::app);

    int iter = 1;
    if (argc >= 1) {
        std::stringstream s(argv[1]);
        s >> iter;
        if (!s)
            iter = 1;
    }
    int pow = 8;
    if (argc >= 2) {
        std::stringstream s(argv[2]);
        s >> pow;
        if (!s)
            pow = 1;
    }

    cout << "type = int, iter = " << iter << ", pow of 10 = " << pow << endl;
    fout << "-----------------------------------------------\ntype = int, iter = " << iter << " pow of 10 = " << pow << endl;
    auto format = cout.setf(std::ios_base::showbase);
    for (int i = 1; i <= pow; ++i) {
        int len = std::pow<int>(10, i);
        
        auto m = mean_int(len, iter);
        
        (cout << "\nsize = " << len << endl << "list.sort(): " << std::fixed << std::setprecision(6) << m.first << endl).setf(format);
        (cout << "copy>sort(vector)>copy: " << std::fixed << std::setprecision(6) << m.second << endl).setf(format);

        (fout << "\nsize = " << len << endl << "list.sort(): " << std::fixed << std::setprecision(6) << m.first << endl).setf(format);
        (fout << "copy>sort(vector)>copy: " << std::fixed << std::setprecision(6) << m.second << endl).setf(format);
    }
    fout.close();

    return 0;
}
