#pragma once

#include <iostream>
#include <string>

#include "../core/class_setting.hpp"
class City;

using namespace std;

namespace player_use_classes {
    
    class player {

        public:
                // main variable
                int hp;
                string name;
                float reputation;
                City* position;
                
                // recourse
                int money;
                int wood;
                int stone;
                int metal;
                int food;

                int cobalt;
                int diamond;
                int hell_metal;
                int paradise_metal;

                // anather variable
                int hungry;

                // enventer

                int have_weapon_id;
                
                // armor
                int helmet_id;
                int bib_id;
                int chisel_id;
                int boots_id;

                player (setting::setting_giver *setting_giver, const string name, const int difficult) {
                
                // main variable
                this->hp = 100;
                this->name = name;
                float reputation = setting_giver->return_player_start_reputation_num(difficult);
                City* position;
                
                // recourse
                int money;
                int wood;
                int stone;
                int metal;
                int food;

                int cobalt;
                int diamond;
                int hell_metal;
                int paradise_metal;

                // anather variable
                int hungry;

                // enventer

                int have_weapon_id;
                
                // armor
                int helmet_id;
                int bib_id;
                int chisel_id;
                int boots_id;

                
            }

            // move mechanic bitwin city

            bool MoveTO(City* destination) {
                for (City* neighbor : position->neighbors) {
                    if (neighbor == destination) {
                        position = neighbor;
                        return true;
                    }
                }
                return false;
            }

            void ShowPositionForChoseWhereCanMove() const {
                cout << "you now in '" << position->name << "' City" << endl;
                cout << "you can move to '";
                for (City* neighbor : position->neighbor) {
                    cout << neighbor->name << ",";
                }
                cout << "' City" << endl;
            }

            void NowPosition() const {
                cout << "you now in '" << position->name << "' City" << endl;
            }

            void CalculateHungry (setting::setting_giver* setting_giver, int difficult, int ticks) 
            {

                    if (ticks % setting_giver->return_player_hungry_tics_num_value(difficult) == 0) {
                        hungry -= 2;
                    }
            
            }


    };

}
