#pragma once

#include <iostream>

#include "../classes/class_player.hpp"
#include "../classes/class_city.hpp"

using namespace std;

namespace core {

class Shower {

    public:

        // player

        void ShowActionForPlayer() {
            cout << "1. move bitwin city" << endl;
            cout << "2. eat food" << endl;
            cout << "enter nothing skip turn" << endl;
        }

        void ShowPLayerMainInfo(player_use_classes::Player* player) 
        {

            if (!player->GetPosition()) {
                cout << "You are not in any city yet!" << endl;
                return;
            }
            cout << "You are now in '" << player->GetPosition()->GetCityName() << "' City" << endl;
            cout << "player '" << player->GetName() << "' HP - " << player->GetHp() << "%" << endl;
            cout << "player '" << player->GetName() << "' hungry - " << player->GetHungry() << "%" << endl;

        }

        // city

        void ShowCityMainInfo(player_use_classes::Player* player)
        {

            class_city::City* city = player->GetPosition();

            if (city->GetCityFree()) {
                cout << "you can't see all city '" << city->GetCityName() << "' info because is not free" << endl;
                cout << "city warriors '" << city->GetWarriors() << "'" << endl;
            } else {
                cout <<  "city '" << city->GetCityName() << "' info" << endl;
                cout << "warriors: " << city->GetWarriors() << endl;
                // TODO;
            }

        }



};



}