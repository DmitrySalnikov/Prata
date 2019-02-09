#include "Sales.h"
#include <iostream>
#include <typeinfo>

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    double vals1[12] = { 1220, 1100, 1122, 2212, 1232, 2334, 2884, 2393, 3302, 2922, 3002, 3544 };
    double vals2[12] = { 12, 11, 22, 21, 32, 34, 28, 29, 33, 29, 32, 35 };
    Sales sales1(2004, vals1, 12);
    LabeledSales sales2("Blogstar", 2005, vals2, 12);

    cout << "First try unit:\n";
    try {
        int i;
        cout << "Year " << sales1.year() << endl;
        for (int i = 0; i < 12; ++i) {
            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year " << sales2.year() << endl;
        cout << "Label " << sales2.label() << endl;
        for (int i = 0; i <= 12; ++i) {
            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of first try unit\n";
    }
    catch (Sales::BadIndex & bi) {
        try {
            LabeledSales::LabeledBadIndex & lbi = dynamic_cast<LabeledSales::LabeledBadIndex &>(bi);
            cout << "Wrong index in LabeledSales: " << lbi.bi_val() << endl;
            cout << "Company: " << lbi.label() << endl;
        }
        catch (std::bad_cast & bc) {
            cout << "Wrong index in Sales: " << bi.bi_val() << endl;
        }
    }
    
    cout << "Second try unit:\n";
    try {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "End of second try unit\n";
    }
    catch (Sales::BadIndex & bi) {
        try {
            LabeledSales::LabeledBadIndex & lbi = dynamic_cast<LabeledSales::LabeledBadIndex &>(bi);
            cout << "Company: " << lbi.label() << endl;
            cout << "Wrong index in LabeledSales: " << lbi.bi_val() << endl;
        }
        catch (std::bad_cast & bc) {
            cout << "Wrong index in Sales: " << bi.bi_val() << endl;
        }
    }

    return 0;
}
