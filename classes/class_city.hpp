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

            int money;
            int wood;
            int metal;

            // people
            int population;
            int farmers;
            int scientists;
            int warriors;
            int free_people;

            int motivation;

            int city_level;

            bool city_free;

        public:

            City(const string name, int id) {
                this->name = name;
                this->id = id;
                
                this->money;
                this-> wood;
                this-> metal;

                // people
                this->population;
                this->farmers;
                this->scientists;
                this->warriors;
                this->free_people;

                this->motivation;

                this->city_level;

                this->city_free;
            }
            
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