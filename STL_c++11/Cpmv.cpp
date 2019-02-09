#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;

class Cpmv {
public:
    Cpmv() : pi(new Info) { cout << "default" << endl; }
    Cpmv(std::string s1, std::string s2) : pi(new Info{s1, s2}) { cout << "string, string" << endl; }
    Cpmv(Cpmv const & obj) : pi(new Info(*obj.pi)) { cout << "copy" << endl; }
    Cpmv(Cpmv && obj) : pi(obj.pi) { obj.pi = nullptr; cout << "move" << endl; }
    ~Cpmv() { delete pi; cout << "destructor" << endl; }
    Cpmv & operator=(Cpmv const & obj) {
        if (this != &obj) {
            delete pi;
            pi = new Info(*obj.pi);
        }
        cout << "=" << endl;
        return *this;
    }
    Cpmv & operator=(Cpmv && obj) {
        if (this != &obj) {
            delete pi;
            pi = obj.pi;
            obj.pi = nullptr;
        }
        cout << "move=" << endl;
        return *this;
    }
    Cpmv operator+(Cpmv const & obj) const { 
        cout << "+" << endl;
        return Cpmv(pi -> qcode + obj.pi -> qcode, pi -> zcode + obj.pi -> zcode); 
    }
    void view() const { cout << pi -> qcode << ' ' << pi -> zcode << endl; }

private:
    struct Info {
        std::string qcode;
        std::string zcode;
    };

    Info * pi;

};

int main() {
    Cpmv a;
    Cpmv b("b", "b");
    Cpmv c(b);
    a = b;
    b = a + c;
    Cpmv d(b + Cpmv("te", "mp"));
    Cpmv e(std::move(b + Cpmv("te", "mp")));

    return 0;
}
