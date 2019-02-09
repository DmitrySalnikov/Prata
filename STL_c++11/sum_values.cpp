#include <iostream>

template <typename T = int>
long double sum_values(T const & t = 0) {
    return t; 
}

template <typename T, typename ... Types>
long double sum_values(T const & sum, Types const & ... values) { 
    return sum + sum_values(values ...); 
}

template <typename T = int>
void view(T const & t = 0) { 
    std::cout << t << " = "; 
}

template <typename T, typename ... Args>
void view(T const & t, Args const & ... args) {
    std::cout << t << " + ";
    view(args ...);
}

template <typename ... Args>
void show(Args const & ... args) {
    view(args ...);
    std::cout << sum_values(args ...) << std::endl;
}

int main() {
    show(416, 213.1211, 's', 'u', 'k', 'a', 525.13547);
    show(1, 2, 3);
    show(123);
    show();
    show('h', 'u', 'y');
    show('d', 'i', 'c', 'k');

    return 0;
}
