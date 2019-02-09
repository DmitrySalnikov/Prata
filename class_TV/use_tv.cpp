#include <iostream>
#include "TV.h"

int main() {
    TV s27;
    s27.settings();
    s27.onoff();
    s27.settings();
    Remote grey;
    grey.settings();
    s27.set_condition(grey);
    grey.settings();
    grey.set_channel(s27, 10);
    grey.volup(s27);
    grey.volup(s27);
    s27.settings();
    if (!grey.set_channel(s27, 101))
        std::cout << "Wrong channel\n";
    grey.set_mode(s27);
    grey.set_input(s27);
    s27.settings();

    return 0;
}
