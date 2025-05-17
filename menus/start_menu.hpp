#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "play_menu.hpp"
#include "../utils/get_difficult.hpp"

using namespace std;

void start_menu() {

    cout << "welcome to tfbw" << endl;

    int input;
    int difficult;

    while (1) {

        cout << "1. start game" << endl;
        cout << "2. exit" << endl;
        cout << "type number of option : ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (input)
        {
        case 1:
            difficult = GetDifficult();
            play_menu(difficult);
            break;
        case 2:
            return;
        default:
            break;
        }



    }



}
