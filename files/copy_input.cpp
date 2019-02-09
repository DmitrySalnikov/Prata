#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream fout("copy_input.txt");
    std::string str;
    std::getline(std::cin, str, '\0');
    fout << str;
    fout.close();
    return 0;
}
