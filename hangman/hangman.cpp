#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <set>
#include <iterator>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::vector;
    using std::set;

    std::ifstream fin("words.txt");
    vector<string> words;
    string temp;
    fin >> temp;
    while (fin) {
        words.push_back(temp);
        fin >> temp;
    }
    fin.close();

    char play = 'y';
    std::random_device g;
    std::uniform_int_distribution<int> r(0, words.size() - 1);
    while (play == 'y') {
        string target = words[r(g)];
        string attempt(target.size(), '-');
        set<char> badchars;
        int guesses = 6;
      
        cout << attempt << endl << guesses << endl;
        while ((guesses > 0) && (attempt != target)) {
            char letter;
            cin >> letter;
            if ((badchars.find(letter) != badchars.end()) || (attempt.find(letter) != string::npos)) { continue; }
            int loc = target.find(letter);
            if (loc == string::npos) { 
                --guesses; 
                badchars.insert(letter); 
            } else {
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << endl << attempt << endl; 
            if (attempt != target) { 
                if (badchars.size()) {
                    std::copy(badchars.begin(), badchars.end(), std::ostream_iterator<char>(cout)); 
                    cout << endl;
                }
                cout << guesses << endl; 
            }
        }

        if (guesses == 0) { cout << endl << target << endl; }
        cout << "\nplay again(y)? ";
        while (cin.get() != '\n');
        cin >> play;
        std::tolower(play);
    }

    return 0;
}
