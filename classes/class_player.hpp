#pragma once

#include <iostream>
#include <string>

#include "../core/class_setting.hpp"

class City;
#include "class_city.hpp"

using namespace std;

namespace player_use_classes {
    
    class Player {

        public:
            // main variable
            int hp;
            string name;
            float reputation;
            class_city::City* position;
            
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

            Player(setting::setting_giver *setting_giver, const string name, const int difficult) {
                // main variable
                this->hp = 100;
                this->name = name;
                this->reputation = setting_giver->return_player_start_reputation_num(difficult);
                this->position = nullptr;

                // resource
                this->money = 0;
                this->wood = 0;
                this->stone = 0;
                this->metal = 0;
                this->food = 0;
                this->cobalt = 0;
                this->diamond = 0;
                this->hell_metal = 0;
                this->paradise_metal = 0;

                this->hungry = setting_giver->return_player_start_hungry_num(difficult);
    
                // armor
                this->have_weapon_id = -1;
                this->helmet_id = -1;
                this->bib_id = -1;
                this->chisel_id = -1;
                this->boots_id = -1;
            }

            // move mechanic bitwin city

            void ShowPositionForChoseWhereCanMove() {
                std::cout << "you now in city: " << position->GetCityName() << endl;
                std::cout << "neighbors city:\n";

                const auto& neighbors = position->GetNeighbors();
                for (size_t i = 0; i < neighbors.size(); ++i) {
                    std::cout << i << ") " << neighbors[i]->GetCityName() << endl;;
                }
            }

            void MoveTOAnotherCity() {
                const auto& neighbors = position->GetNeighbors();
                int choice = -1;

                std::cout << "type number of city for move: ";
                std::cin >> choice;

                if (choice >= 0 && static_cast<size_t>(choice) < neighbors.size()) {
                    position = neighbors[choice];
                    std::cout << "you move to " << position->GetCityName() << "!" << endl;;
                } else {
                    std::cout << "invalid option" << endl;;
                }
            }

            void CalculateHungry(setting::setting_giver* setting_giver, int difficult, int ticks) {
                if (ticks % setting_giver->return_player_hungry_tics_num_value(difficult) == 0) {
                    hungry = max(0, hungry - 2);
                }
            }

            void EatFood() {
                if (food <= 0 ) {
                    cout << "you can't eat food because you don't have food" << endl;
                } else {
                    this->food--;
                    this->hungry + 2;
                }
            }
    };
}
