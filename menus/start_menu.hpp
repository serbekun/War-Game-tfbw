#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "play_menu.hpp"
#include "../utils/get_difficult.hpp"

using namespace std;

void start_menu(bool test_mod) {

    cout << "welcome to tfbw" << endl;

    string player_name;
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
            cout << "type your nickname in game : ";
            getline(cin, player_name);
            play_menu(difficult, player_name, test_mod);
            break;
        case 2:
            return;
        default:
            break;
        }



    }



}
