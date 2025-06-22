#pragma once

#include <iostream>
#include <string>

#include "class_setting.hpp"
#include "../classes/class_player.hpp"


namespace core {

class player_hp_calculation {

    public:

        void CalculatePlayerHpHungryMechanic(
            player_use_classes::Player* player,
            const int difficult,
            setting::setting_giver* setting_giver)
        {
        
            const int hungry_threshold = setting_giver->return_player_hungry_num_when_start_health(difficult);
            const int hp_to_add = setting_giver->return_player_full_hungry_hp_add(difficult);

            if (player->GetHungry() > hungry_threshold)
            {
                player->AddHp(hp_to_add);
            }
        }

        
};

}