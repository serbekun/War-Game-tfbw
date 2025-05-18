#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Player;
#include "class_player.hpp"

using namespace std;

namespace class_city {

    class City {

        public:

            int id;
            string name;
            vector<City*> neighbors;

            int money;
            int wood;
            int metal;

            int warrios;
            int motivation;

            int city_level;

            bool city_free;

            City(const string name  ) {
                this->name = name;
                this->id = id;
            }

            void CityAllSetting() {
                
            } // ````````````````````````````````````````````` not create
            
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