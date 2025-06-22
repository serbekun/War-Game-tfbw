#pragma once

#include <iostream>
#include <string>

#include "../classes/class_player.hpp"

namespace core {

class limit_cater {

    private:
        
        // set consts
        const unsigned char player_max_hp = 100;
        const unsigned char player_max_hungry = 100;


    public:

        void CatPlayerLimits(player_use_classes::Player* player) 
        {

            // cat player hp limit
            if (player->GetHp() > player_max_hp)
                player->SetHp(player_max_hp);

            // cat player hungry
            if (player->GetHungry())
                player->SetHungry(player_max_hungry);

        }



};

}