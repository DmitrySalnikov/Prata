#include <fstream>
#include <iostream>
#include <stdexcept>
#include "employee.h"

void eatline(std::istream & in = cin) { while (in && in.get() != '\n'); }
void empty() {}

int main() {
    std::fstream file("employees.txt", std::ios_base::in);
    abstr_emp * temp;
    char ch = 0;

    cout << "-------------------------------\n\nEmployees now:\n---\n";
    if (file) {
        file.get(ch);
        eatline(file);
    }
    try {
        while (file) {
            switch (ch) {
                case '0' : temp = new employee; break;
                case '1' : temp = new manager; break;
                case '2' : temp = new fink; break;
                case '3' : temp = new highfink; break;
                default : throw std::runtime_error("");
            }
            temp -> read(file);
            eatline(file);
            temp -> show();
            cout << endl;
            delete temp;
            file.get(ch);
            eatline(file);
        }
    }
    catch (std::exception & ex) {}
    file.close();

    file.open("employees.txt", std::ios_base::out | std::ios_base::app);
    if (!file.is_open()) { std::cerr << "Error file \"employees.txt\""; return 0; }
    cout << "-------------------------------\n\nEnter new employees(0-3 or q):\n---\n";
    cin.get(ch);
    eatline();
    while (file && (ch != 'q')) {
        try {
            switch (ch) {
                case '0' : temp = new employee; break;
                case '1' : temp = new manager; break;
                case '2' : temp = new fink; break;
                case '3' : temp = new highfink; break;
                default : throw std::runtime_error("Incorrect symbol");
            }
            temp -> set();
            eatline();
            cout << endl;
            temp -> write(file);
            delete temp;
        }
        catch(std::exception & ex) { cout << ex.what() << endl; }
        cout << "Enter employees(0-3 or q):\n";
        cin.get(ch);
        eatline();
    }
    file.close();

    cout << "-------------------------------\n\nEmployees now:\n---\n";
    file.open("employees.txt", std::ios_base::in);
    if (file) {
        file.get(ch);
        eatline(file);
    }
    try {
        while (file) {
            switch (ch) {
                case '0' : temp = new employee; break;
                case '1' : temp = new manager; break;
                case '2' : temp = new fink; break;
                case '3' : temp = new highfink; break;
                default : throw std::runtime_error("");
            }
            temp -> read(file);
            eatline(file);
            temp -> show();
            cout << endl;
            delete temp;
            file.get(ch);
            eatline(file);
        }
    }
    catch (std::exception & ex) {}
    file.close();
    cout << "-------------------------------\n";

    return 0;
}
