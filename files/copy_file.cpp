#include <fstream>
#include <iostream>

int main(int argc, char ** argv) {
    if (argc < 3) {
        std::cerr << "Need names of files\n";
        return 0;
    }
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    if(!fin.is_open() || !fout.is_open()) {
        std::cerr << "Can't open files\n";
        return 0;
    }
    std::string str;
    std::getline(fin, str, '\0');
    fin.close();
    fout << str;
    fout << "addition\n";
    fout.close();

    return 0;
}
