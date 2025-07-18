#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace setting {

    class setting_giver {

        private:

            // player
            const int player_hungry_tics_num[5] = {25, 20, 15, 10, 10};
            const int player_start_hungry_num[5] = {100, 90, 70, 50, 20};
            const double player_start_reputation_num[5] = {30.0, 25.0, 15.0, 5.0, 1.0};
            
            // hungry mechanics
            const int player_hungry_num_when_start_health[5] = {50, 60, 70, 80, 90};
            const int player_full_hungry_hp_add[5] = {10, 8, 6, 4, 2};

            // city
            const string city_names[24] = 
            {"astralith", "postblavn", "kinland", "aeliris", "ventaria",
            "luminara", "eolor", "borealis", "terramo", "cirena",
            "orbita","skygard", "rshagrad", "ainorar", "kraipech",
            "gulkan", "sdah", "alterc", "koronavis", "zolacity",
            "beregrod", "nolodar", "enrich", "ominda"
            };

            const int city_start_money[5] = {60000, 50000, 30000, 20000, 10000};
            const int city_start_money_diapason[2] = {-10000, 10000};
            
            const int city_start_resource[5] = {1000, 800, 600, 400, 100};
            const int city_start_resource_diapason[2] = {-80, +80};

            const int city_start_population = 25000;
            const int city_start_population_diapason[2] ={-5000, 5000};
            
        public:

            string return_city_names(int const num_city_name) 
            {
                switch (num_city_name) {
                case 1: return city_names[0];
                case 2: return city_names[1];
                case 3: return city_names[2];
                case 4: return city_names[3];
                case 5: return city_names[4];
                case 6: return city_names[5];
                case 7: return city_names[6];
                case 8: return city_names[7];
                case 9: return city_names[8];
                case 10: return city_names[9];
                case 11: return city_names[10];
                case 12: return city_names[11];
                case 13: return city_names[12];
                case 14: return city_names[13];
                case 15: return city_names[14];
                case 16: return city_names[15];
                case 17: return city_names[16];
                case 18: return city_names[17];
                case 19: return city_names[18];
                case 20: return city_names[19];
                case 21: return city_names[20];
                case 22: return city_names[21];
                case 23: return city_names[22];
                case 24: return city_names[23];
                default: return "unknown";
                }
            }

            int return_city_start_money(const int difficult) 
            {
                switch (difficult) {
                    case 1: return city_start_money[0];
                    case 2: return city_start_money[1];
                    case 3: return city_start_money[2];
                    case 4: return city_start_money[3];
                    case 5: return city_start_money[4];
                    default: return city_start_money[2];
                }
            }

            int return_city_start_money_diapason(int num /*0 = minus diapason, default = plus diapason */) 
            {
                switch (num)
                {
                case 0: return city_start_money_diapason[0];
                default: return city_start_money_diapason[1];                    
                }
            }

            int return_city_start_resource(int difficult) 
            {
                switch (difficult)
                {
                case 1: return city_start_resource[0];
                case 2: return city_start_resource[1];
                case 3: return city_start_resource[2];
                case 4: return city_start_resource[3];
                case 5: return city_start_resource[4];
                default: return city_start_resource[2];
                }
            }

            int return_city_start_resource_diapason(int num /*0 = minus diapason, default = plus diapason */) 
            {
                switch (num)
                {
                case 0: return city_start_resource_diapason[0];
                default: return city_start_resource_diapason[1];
                }
            }

            int return_city_start_population() {return city_start_population;}

            int return_city_start_population_diapason(int num) 
            {
                switch (num) {
                case 0: return city_start_population_diapason[0];
                default: return city_start_population_diapason[1];
                }
            }

            int return_player_hungry_tics_num_value(int const difficult) 
            {
                switch (difficult) {
                    case 1: return player_hungry_tics_num[0];
                    case 2: return player_hungry_tics_num[1];
                    case 3: return player_hungry_tics_num[2];
                    case 4: return player_hungry_tics_num[3];
                    case 5: return player_hungry_tics_num[4];
                    default: return player_hungry_tics_num[2];
                }
            }

            int return_player_start_hungry_num(int const difficult) 
            {
                switch (difficult) {
                    case 1: return player_start_hungry_num[0];
                    case 2: return player_start_hungry_num[1];
                    case 3: return player_start_hungry_num[2];
                    case 4: return player_start_hungry_num[3];
                    case 5: return player_start_hungry_num[4];
                    default: return player_start_hungry_num[2];
                }
            }

            float return_player_start_reputation_num(int const difficult) 
            {
                switch (difficult) {
                case 1: return player_start_reputation_num[0];
                case 2: return player_start_reputation_num[1];
                case 3: return player_start_reputation_num[2];
                case 4: return player_start_reputation_num[3];
                case 5: return player_start_reputation_num[4];
                default: return player_start_reputation_num[2];  
                }
            }

            /* player mechanics setting */

            int return_player_hungry_num_when_start_health(int const difficult)
            {
                switch (difficult)
                {
                case 1: return player_hungry_num_when_start_health[0];
                case 2: return player_hungry_num_when_start_health[1];
                case 3: return player_hungry_num_when_start_health[2];
                case 4: return player_hungry_num_when_start_health[3];
                case 5: return player_hungry_num_when_start_health[4];
                default: return player_hungry_num_when_start_health[2];
                }
            }

            int return_player_full_hungry_hp_add(int const difficult)
            {
                switch (difficult) 
                {
                    case 1: return player_full_hungry_hp_add[0];
                    case 2: return player_full_hungry_hp_add[1];
                    case 3: return player_full_hungry_hp_add[2];
                    case 4: return player_full_hungry_hp_add[3];
                    case 5: return player_full_hungry_hp_add[4];
                    default: return player_full_hungry_hp_add[5];
                }

            }

    };

}
