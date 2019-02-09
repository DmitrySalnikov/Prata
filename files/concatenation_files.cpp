#include <fstream>
#include <iostream>

int main(int argc, char ** argv) {
    if (argc < 3) {
        std::cerr << "Need names of files\n";
        return 0;
    }
    std::ifstream fin1(argv[1]);
    std::ifstream fin2(argv[2]);
    std::ofstream fout(argv[3]);
    if(!fin1.is_open() || !fin2.is_open() || !fout.is_open()) {
        std::cerr << "Can't open files\n";
        return 0;
    }
    std::string str1, str2;
    std::getline(fin1, str1);
    std::getline(fin2, str2);
    while(fin1 || fin2) {
        if(fin1)
            fout << str1 << ' ';
        fout << str2 << std::endl;
        std::getline(fin1, str1);
        std::getline(fin2, str2);
    }
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}
