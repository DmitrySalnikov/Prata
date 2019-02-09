#include <iostream>
#include <cmath>
#include "exc_mean2.h"

double hmean(double a, double b) throw (BadHmean) {
    double e = 1e-15;
    if (std::abs(a + b) < e)
        throw BadHmean(a, b);

    return 2 * a * b / (a + b);
}

double gmean(double a, double b) throw (BadGmean) {
    if (a  < 0 || b < 0)
        throw BadGmean(a, b);

    return std::sqrt(a * b);
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    double x, y;
    cout << "Enter two quantityes: ";
    while (cin >> x >> y) {
        try {
            double z = hmean(x, y);
            double t = gmean(x, y);
            cout << "Harmonic mean " << z << endl << "Geometric mean " << t << endl;        
        }
        catch (BadMean & bm) {
            bm.description();
        }

        cout << "Enter two quantityes: ";

    }

    return 0;
}
