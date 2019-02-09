#include <iostream>

int main() {
    int count = 0;
    while (std::cin.get() != '$') 
        ++count;
    std::cin.putback('$');
    std::cout << count << std::endl;
    std::cout << char(std::cin.get()) << std::endl;

    return 0;
}
