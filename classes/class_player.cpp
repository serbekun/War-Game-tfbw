#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace player_use_classes {
    
    class player {

        public:
            
            // main variable
            int hp;
            string name;
            float reputation;
            int position;
            
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

            void calculate_hungry (const int difficult, int ticks) 
            {

                if (difficult == 1) {
                    if (ticks % )
                }

            }


    };

}
