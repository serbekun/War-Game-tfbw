#pragma once

#include <iostream>

#include "../classes/class_player.hpp"

using namespace std;

namespace core {

class Shower {

    public:

        void NowPosition(player_use_classes::Player* player) const {
            if (!player->position) {
                cout << "You are not in any city yet!" << endl;
                return;
            }
            cout << "You are now in '" << player->position->name << "' City" << endl;
        }

        void ShowActionForPlayer() {
            cout << "1. move bitwin city" << endl;
            cout << "2. eat food" << endl;
            cout << "enter nothing skip turn" << endl;
        }

};



}