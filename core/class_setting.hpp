#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace setting {

    class setting_giver {

        private:
            const int player_hungry_tics_num[5] = {25, 20, 15, 10, 10};
            const int player_start_hungry_num[5] = {100, 90, 70, 50, 20};
            const double player_start_reputation_num[5] = {30.0, 25.0, 15.0, 5.0, 1.0};
            
            const string city_names[4] = {"astralith", "test1", "test2", "test3"}; 

        public:

            string return_city_names(int const num_city_name) {
                switch (num_city_name) {
                case 1: return city_names[0];
                case 2: return city_names[1];
                case 3: return city_names[2];
                case 4: return city_names[3];
                default: return "unknown";
                }
            }

            int return_player_hungry_tics_num_value(int const difficult) {
                switch (difficult) {
                    case 1: return player_hungry_tics_num[0];
                    case 2: return player_hungry_tics_num[1];
                    case 3: return player_hungry_tics_num[2];
                    case 4: return player_hungry_tics_num[3];
                    case 5: return player_hungry_tics_num[4];
                    default: return player_hungry_tics_num[2];
                }
            }

            int return_player_start_hungry_num(int const difficult) {
                switch (difficult) {
                    case 1: return player_start_hungry_num[0];
                    case 2: return player_start_hungry_num[1];
                    case 3: return player_start_hungry_num[2];
                    case 4: return player_start_hungry_num[3];
                    case 5: return player_start_hungry_num[4];
                    default: return player_start_hungry_num[2];
                }
            }

            float return_player_start_reputation_num(int const difficult) {
                switch (difficult) {
                case 1: return player_start_reputation_num[0];
                case 2: return player_start_reputation_num[1];
                case 3: return player_start_reputation_num[2];
                case 4: return player_start_reputation_num[3];
                case 5: return player_start_reputation_num[4];
                default: return player_start_reputation_num[2];  
                }
            }
    };

}