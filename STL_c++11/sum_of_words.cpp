#include <iostream>
#include <string>
#include <set>
#include <iterator>

int main() {
    std::string s;
    std::set<char> set;
    do {
        std::cin >> s;
        long long sum = 0;
        for (auto x : s)
            sum += x;
        std::cout << sum << std::endl;
        std::copy(s.begin(), s.end(), std::insert_iterator<std::set<char>>(set, set.begin()));
        for (auto x : set)
            std::cout << char(x) << " = " << int(x) << std::endl;
    } while(s[0] != 0);

    return 0;
}
