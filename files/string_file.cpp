#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::copy;
using std::vector;
using std::getline;
using std::for_each;
using std::ios_base;
using std::size_t;

void show(string const & s) { cout << s << endl; }

class Store {
public:
    Store(std::ofstream & f) : fout(f) {}
    void operator()(string s) { 
        size_t l = s.size();
        fout.write((char *)&l, sizeof(l)); 
        fout.write(s.data(), l); 
    }

private:
    std::ofstream & fout;
};

void getStr(std::istream & fin, vector<string> & v) {
    size_t l = 0;
    fin.read((char *)&l, sizeof(size_t));
    while (fin) {
        string temp(l, 0);
        fin.read(&temp[0], l);
        v.push_back(temp);
        fin.read((char *)&l, sizeof(size_t));
    }
}

int main() {
    vector<string> vostr;
    string temp;
    cout << "Enter strings:\n";
    while (getline(cin, temp) && temp[0])
        vostr.push_back(temp);
    cout << "Your input:\n";
    for_each(vostr.begin(), vostr.end(), show);
    std::ofstream fout("strings.txt", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    vector<string> vistr;
    std::ifstream fin("strings.txt", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        std::cerr << "Couldn't open file \"strings.txt\' for input\n";
        std::exit(EXIT_FAILURE);
    }
    getStr(fin, vistr);
    cout << "Strings from file \"strings.txt\":\n";
    for_each(vistr.begin(), vistr.end(), show);

    return 0;
}
