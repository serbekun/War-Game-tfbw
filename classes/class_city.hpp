#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../core/class_setting.hpp"

#include "../utils/class_rng.hpp"

class Player;
#include "class_player.hpp"

using namespace std;

namespace class_city {

    class City {

        private:
        
            int id;
            string name;
            vector<City*> neighbors;

            int bases_id[2];

            int money;
            
            int wood;
            int metal;
            int food;

            // people
            int population;
            int warriors;

            int motivation;

            int city_level;

            bool city_free;

        public:

            City(const int difficult, const string name, int id, utils::rng *rng, setting::setting_giver *setting_giver) {
                this->name = name;
                this->id = id;
                
                int money = setting_giver->return_city_start_money(difficult);
                int money_change_diapason = rng->
                GetRandomIntWithDiapason(setting_giver->return_city_start_money_diapason(0),
                setting_giver->return_city_start_money_diapason(1));
                
                this->money = money += money_change_diapason;
                
                int wood = setting_giver->return_city_start_resource(difficult);
                wood += rng->
                GetRandomIntWithDiapason(setting_giver->return_city_start_resource_diapason(0),
                setting_giver->return_city_start_resource_diapason(1));
                int metal = setting_giver->return_city_start_resource(difficult);
                metal += rng->
                GetRandomIntWithDiapason(setting_giver->return_city_start_resource_diapason(0),
                setting_giver->return_city_start_resource_diapason(1));
                int food = setting_giver->return_city_start_resource(difficult);
                food += rng->
                GetRandomIntWithDiapason(setting_giver->return_city_start_resource_diapason(0),
                setting_giver->return_city_start_resource_diapason(1));

                this-> wood = wood;
                this-> metal = metal;
                this-> food = food;

                // people
                
                int population = setting_giver->return_city_start_population();
                population += rng->
                GetRandomIntWithDiapason(setting_giver->return_city_start_money_diapason(0),
                setting_giver->return_city_start_population_diapason(1));

                this->population = population;
                this->warriors; // TODO

                this->motivation;

                this->city_level;

                this->city_free;
            }

            // getters
            int GetMoney() const { return money; }
            int GetWood() const { return wood; }
            int GetMetal() const { return metal; }
            int GetFood() const { return food; }
            int GetPopulation() const { return population; }
            int GetWarriors() const { return warriors; }
            int GetMotivation() const { return motivation; }
            int GetCityLevel() const { return city_level; }
            bool GetCityFree() const { return city_free; }

            // setters
            void SetMoney(int value) { money = value; }
            void SetWood(int value) { wood = value; }
            void SetMetal(int value) { metal = value; }
            void SetFood(int value) { food = value; }
            void SetPopulation(int value) { population = value; }
            void SetWarriors(int value) { warriors = value; }
            void SetMotivation(int value) { motivation = value; }
            void SetCityLevel(int value) { city_level = value; }
            void SetCityFree(bool state) { city_free = state; }

            // adder
            void AddMoney(int value) { money += value; }
            void AddWood(int value) { wood += value; }
            void AddMetal(int value) { metal += value; }
            void AddFood(int value) { food += value; }
            void AddPopulation(int value) { population += value; }
            void AddWarriors(int value) { warriors += value; }
            void AddMotivation(int value) { motivation += value; }
            void AddCityLevel(int value) { city_level += value; }

            // main funk

            void AddNeighbor(City* city) {
                if (city && city != this && 
                    find(neighbors.begin(), neighbors.end(), city) == neighbors.end()) {
                    neighbors.push_back(city);
                }
            }

            vector<City*>& GetNeighbors() {
            return neighbors;
            }

            std::string GetCityName() const {
                return name;
            }

    };


}
