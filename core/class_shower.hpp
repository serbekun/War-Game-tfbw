#pragma once

#include <iostream>

#include "../classes/class_player.hpp"

using namespace std;

namespace core {

class Shower {

    public:

        void ShowActionForPlayer() {
            cout << "1. move bitwin city" << endl;
            cout << "2. eat food" << endl;
            cout << "enter nothing skip turn" << endl;
        }

        void ShowPLayerMainInfo(player_use_classes::Player* player) {

            if (!player->GetPosition()) {
                cout << "You are not in any city yet!" << endl;
                return;
            }
            cout << "You are now in '" << player->GetPosition()->name << "' City" << endl;
            cout << "player HP - " << player->GetHp() << "%" << endl;
            cout << "player hungry - " << player->GetHungry() << "%" << endl;

        }

};



}