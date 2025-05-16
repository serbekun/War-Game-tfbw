#pragma once

#include <iostream>
#include <string>
#include <vector>

class PLayer;

using namespace std;

namespace class_city {

    class City {

        public:

            string name;
            vector<City*> neighbors;

            int money;
            int wood;
            int metal;

            City(const string name) {
                this->name = name;
            }

            void AddNeighbor(City* neighbor) {
                neighbors.push_back(neighbor);
            }


    };


}