    #pragma once

    #include <iostream>
    #include <string>
    #include <limits>

    // include core
    #include "../core/class_setting.hpp"
    #include "../core/class_shower.hpp"
    #include "../utils/class_rng.hpp"

    // include play class
    #include "../classes/class_player.hpp"
    #include "../classes/class_city.hpp"
    
    using namespace std;
    
    void play_menu (int difficult, string player_name, bool test_mod) {

        // init value
        int turn_count;
        int input;

        // init core classes
        setting::setting_giver* setting_giver = new setting::setting_giver;
        core::Shower* shower = new core::Shower;
        utils::rng* rng = new utils::rng;


        // inti play classes
        player_use_classes::Player* player = new player_use_classes::Player(setting_giver, player_name,  difficult);
        
        // create city
        int *city_id = new int(1);
        int *city_name_num = new int(1);
        class_city::City* city_astralith = 
        new class_city::City(difficult, setting_giver->
            return_city_names(*city_name_num), *city_id, rng, setting_giver);
        
        (*city_id)++;
        (*city_name_num)++;
        
        class_city::City* city_postblavn = 
        new class_city::City(difficult, setting_giver->
            return_city_names(*city_name_num), *city_id, rng, setting_giver);
        
        (*city_id)++;
        (*city_name_num)++;
        
        class_city::City* city_kinland = 
        new class_city::City(difficult, setting_giver->
            return_city_names(*city_name_num), *city_id, rng, setting_giver);
        
        (*city_id)++;
        (*city_name_num)++;

        // free unusual variable
        delete(city_id);
        delete(city_name_num);

        // set city free station

        // add city neighbors
        city_astralith->AddNeighbor(city_postblavn);

        city_postblavn->AddNeighbor(city_astralith);
        city_postblavn->AddNeighbor(city_kinland);

        city_kinland->AddNeighbor(city_postblavn);


        // set player start position
        player->SetPosition(city_astralith);

        while (1) 
        {

            cout << "==========================================" << endl;
            
            shower->ShowPLayerMainInfo(player, );
            shower->ShowActionForPlayer();

            cout << "type option of action what you want to do : ";
            if (cin.peek() == '\n') {
                // if entered only enter skip
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin >> input;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (input) {
                    case 1:
                        player->ShowPositionForChoseWhereCanMove();
                        player->MoveTOAnotherCity();
                        break;
                    case 2:
                        player->EatFood();
                        break;
                    default:
                        break;
                }
            }

            player->CalculateHungry(setting_giver, difficult, turn_count);

            turn_count++;
        }

        // free all classes

        // delete core classes
        delete(setting_giver);
  
        // delete play classes
        delete(player);

        // delete city
        delete(city_astralith);

        
}