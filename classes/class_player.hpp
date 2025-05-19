#pragma once

#include <iostream>
#include <string>

#include "../core/class_setting.hpp"

class City;
#include "class_city.hpp"

using namespace std;

namespace player_use_classes {
    
    class Player {

        private:
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

            // value for calculate reputation

            // good
            int have_many_enemy_kill;
            int have_many_city_save;
            int have_many_money_giv_to_country;

            // bad 
            int have_many_money_steal;

            // mechanics variable

            int wait_;

        public:

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
                this->food = 10;
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

            // class getter

            int GetHp() const { return hp; }
            string GetName() const { return name; }
            float GetReputation() const { return reputation; }
            class_city::City* GetPosition() const { return position; }

            int GetMoney() const { return money; }
            int GetWood() const { return wood; }
            int GetStone() const { return stone; }
            int GetMetal() const { return metal; }
            int GetFood() const { return food; }

            int GetCobalt() const { return cobalt; }
            int GetDiamond() const { return diamond; }
            int GetHellMetal() const { return hell_metal; }
            int GetParadiseMetal() const { return paradise_metal; }

            int GetHungry() const { return hungry; }

            int GetHaveWeaponId() const { return have_weapon_id; }

            int GetHelmetId() const { return helmet_id; }
            int GetBibId() const { return bib_id; }
            int GetChiselId() const { return chisel_id; }
            int GetBootsId() const { return boots_id; }

            int GetHaveManyEnemyKill() const { return have_many_enemy_kill; }
            int GetHaveManyCitySave() const { return have_many_city_save; }
            int GetHaveManyMoneyGivToCountry() const { return have_many_money_giv_to_country; }

            int GetHaveManyMoneySteal() const { return have_many_money_steal; }

            // setter all

            void SetHp(int new_hp) { hp = new_hp; }
            void SetName(const string& new_name) { name = new_name; }
            void SetReputation(float new_reputation) { reputation = new_reputation; }
            //void SetPosition(class_city::City* new_position) { position = new_position; }

            void SetMoney(int new_money) { money = new_money; }
            void SetWood(int new_wood) { wood = new_wood; }
            void SetStone(int new_stone) { stone = new_stone; }
            void SetMetal(int new_metal) { metal = new_metal; }
            void SetFood(int new_food) { food = new_food; }

            void SetCobalt(int new_cobalt) { cobalt = new_cobalt; }
            void SetDiamond(int new_diamond) { diamond = new_diamond; }
            void SetHellMetal(int new_hell_metal) { hell_metal = new_hell_metal; }
            void SetParadiseMetal(int new_paradise_metal) { paradise_metal = new_paradise_metal; }

            void SetHungry(int new_hungry) { hungry = new_hungry; }

            void SetHaveWeaponId(int new_weapon_id) { have_weapon_id = new_weapon_id; }

            void SetHelmetId(int new_helmet_id) { helmet_id = new_helmet_id; }
            void SetBibId(int new_bib_id) { bib_id = new_bib_id; }
            void SetChiselId(int new_chisel_id) { chisel_id = new_chisel_id; }
            void SetBootsId(int new_boots_id) { boots_id = new_boots_id; }

            void SetHaveManyEnemyKill(int new_count) { have_many_enemy_kill = new_count; }
            void SetHaveManyCitySave(int new_count) { have_many_city_save = new_count; }
            void SetHaveManyMoneyGivToCountry(int new_count) { have_many_money_giv_to_country = new_count; }

            void SetHaveManyMoneySteal(int new_count) { have_many_money_steal = new_count; }


            // setters add

            void AddHp(int value) { hp += value; }
            void AddReputation(float value) { reputation += value; }
            void AddMoney(int value) { money += value; }
            void AddWood(int value) { wood += value; }
            void AddStone(int value) { stone += value; }
            void AddMetal(int value) { metal += value; }
            void AddFood(int value) { food += value; }

            void AddCobalt(int value) { cobalt += value; }
            void AddDiamond(int value) { diamond += value; }
            void AddHellMetal(int value) { hell_metal += value; }
            void AddParadiseMetal(int value) { paradise_metal += value; }

            void AddHungry(int value) { hungry += value; }

            void AddHaveWeaponId(int value) { have_weapon_id += value; }

            void AddHelmetId(int value) { helmet_id += value; }
            void AddBibId(int value) { bib_id += value; }
            void AddChiselId(int value) { chisel_id += value; }
            void AddBootsId(int value) { boots_id += value; }

            void AddHaveManyEnemyKill(int value) { have_many_enemy_kill += value; }
            void AddHaveManyCitySave(int value) { have_many_city_save += value; }
            void AddHaveManyMoneyGivToCountry(int value) { have_many_money_giv_to_country += value; }

            void AddHaveManyMoneySteal(int value) { have_many_money_steal += value; }
            
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

            void SetPosition(class_city::City* new_pos) {
                position = new_pos;
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
                    this->hungry += 2;
                    cout << "after eat you have '" << food << "'" << endl;
                    cout << "hungry took value " << hungry << "%" << endl;
                }
            }
    };
}
