#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::set;
    using std::copy;

    set<string> f;
    string temp;

    std::ifstream fin("mat.txt");
    if (!fin) { std::cerr << "Error open mat.txt\n"; return 0; }
    while (fin >> temp)
        f.insert(temp);
    fin.close();

    std::ostream_iterator<string> i_cout(cout, " ");
    cout << "Mat's friends: ";
    copy(f.begin(), f.end(), i_cout);
    cout << endl;

    std::ofstream fout("matnpat.txt");
    std::ostream_iterator<string> i_fout(fout, "\n");
    copy(f.begin(), f.end(), i_fout);

    f.clear();

    fin.open("pat.txt");
    if (!fin) { std::cerr << "Error open pat.txt\n"; return 0; }
    while (fin >> temp)
        f.insert(temp);
    fin.close();

    cout << "Pat's friends: ";
    copy(f.begin(), f.end(), i_cout);
    cout << endl;

    copy(f.begin(), f.end(), i_fout);

    fout.close();

    return 0;
}
