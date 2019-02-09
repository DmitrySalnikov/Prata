#include <iostream>
#include <set>
#include <string>
#include <iterator>

template <typename T>
int reduce(T * a, int n) {
    std::set<T> b;

    std::copy(a, a + n, std::insert_iterator<std::set<T>>(b, b.end()));
    std::copy(b.begin(), b.end(), a);

    return b.size();
}

int main() {
    using std::cout;
    using std::endl;

    long a[] = {1, 9, 0 -5, -9, -5, -9, 0, 1, 3};
    int n = reduce(a, sizeof(a) / sizeof(a[0]));

    cout << n << ": ";
    std::copy(a, a + n, std::ostream_iterator<long>(cout, " "));

    std::string b[] = {"hui", "pizda", "skovoroda", "dgigurda", "dgigurda", "dgigurda", "1", "1", "hui"};
    n = reduce(b, sizeof(b) / sizeof(b[0]));

    cout << endl << n << ": ";
    std::copy(b, b + n, std::ostream_iterator<std::string>(cout, " "));

    return 0;
}
