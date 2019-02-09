#include <iostream>
#include <cmath>
#include "exc_mean1.h"

double hmean(double a, double b) throw (BadHmean) {
    double e = 1e-15;
    if (std::abs(a + b) < e)
        throw BadHmean("Error in hmean(x, y): x = -y");

    return 2 * a * b / (a + b);
}

double gmean(double a, double b) throw (BadGmean) {
    if (a  < 0 || b < 0)
        throw BadGmean("Error in gmean(x, y): x or y is negative");

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
        catch (BadHmean & bh) {
            cout << bh.what() << endl;
        }
        catch (BadGmean & bg) {
            cout << bg.what() << endl;
        }

        cout << "Enter two quantityes: ";

    }

    return 0;
}
