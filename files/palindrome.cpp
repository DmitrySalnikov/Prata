#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(std::string const & s) {
    auto i = s.begin();
    auto j = s.end() - 1;
    
    while (true) {
        if (std::isalpha(*i))
            break;
        ++i;
    }

    while (true) {
        if (std::isalpha(*j))
            break;
        --j;
    }
    
    while (i < j) {
        if (std::tolower(*i) != std::tolower(*j))
            return false;
        ++i; --j;

        while (true) {
            if (std::isalpha(*i))
                break;
            ++i;
        }

        while (true) {
            if (std::isalpha(*j))
                break;
            --j;
        }
    }
    
    return true;
}

int main() {
    std::cout << is_palindrome("otto") << std::endl;
    std::cout << is_palindrome("ototo") << std::endl;
    std::cout << is_palindrome("otoao") << std::endl;
    std::cout << is_palindrome("Madam, I'm Adam") << std::endl;
    std::cout << is_palindrome("Madam, I am Adam") << std::endl;

    return 0;
}
