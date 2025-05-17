#include <iostream>
#include <string>
#include "menus/start_menu.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    bool test_mod = false;

    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "test") {
            test_mod = true;
            break;
        }
    }

    if (test_mod) {
        cout << "debug test mod active" << endl;
    }

    start_menu(test_mod);

    return 0;
    
}