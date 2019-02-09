#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>

using std::vector;

vector<int> lotto(int max, int num) {
    vector<int> temp(max);
    for (int i = 1; i <= max; ++i)
        temp[i - 1] = i;
    
    std::random_shuffle(temp.begin(), temp.end());

    std::sort(temp.begin(), temp.begin() + num);

    return std::vector<int>(temp.begin(), temp.begin() + num);
}

void view(vector<int> const & a) {
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    std::srand(time(0));

    view(lotto(51,6));

    return 0;
}
