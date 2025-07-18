#pragma once

#include <iostream>
#include <string>
#include <limits>

// include core
#include "../core/class_setting.hpp"
#include "../core/class_shower.hpp"
#include "../utils/class_rng.hpp"
#include "../core/class_limit_cater.hpp"
#include "../core/class_player_hp_calculation.hpp"

// include play class
#include "../classes/class_player.hpp"
#include "../classes/class_city.hpp"
    
using namespace std;
    
void play_menu (int difficult, string player_name, bool test_mod) {

    // init value
    int turn_count = 0;
    int input;
    bool exit = 1;

    // init core classes 
    setting::setting_giver* setting_giver = new setting::setting_giver;
    core::Shower* shower = new core::Shower;
    utils::rng* rng = new utils::rng;
    core::limit_cater* Limit_cater = new core::limit_cater;
    core::player_hp_calculation* Player_hp_calculation = new core::player_hp_calculation;
    
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
    // TODO
    
    // add city neighbors
    city_astralith->AddNeighbor(city_postblavn);

    city_postblavn->AddNeighbor(city_astralith);
    city_postblavn->AddNeighbor(city_kinland);

    city_kinland->AddNeighbor(city_postblavn);


    // set player start position
    player->SetPosition(city_astralith);

    while (exit) 
    {



        // game mechanics
        Player_hp_calculation->CalculatePlayerHpHungryMechanic(player, difficult, setting_giver);

        cout << "==========="<< turn_count << "============" << endl;
            
        shower->ShowPLayerMainInfo(player);
        shower->ShowActionForPlayer();
            
        cout << "==========================================" << endl;

        cout << "type option of action what you want to do : ";
        if (cin.peek() == '\n') {
            // if entered only enter skip
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            if (!(cin >> input)) {  // Check if input failed
                cin.clear();  // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear buffer
                cout << "Invalid input. Please enter a number." << endl;
                continue;  // Skip rest of loop iteration
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (input) {
                case 0:
                    cout << "exiting" << endl;
                    return;
                case 1:
                    player->ShowPositionForChoseWhereCanMove();
                    player->MoveToAnotherCity();
                    break;
                case 2:
                    player->EatFood();
                    break;
                case -1:
                    exit = 0;
                default:
                    break;
            }
        }

        // game mechanics start
        player->CalculateHungry(setting_giver, difficult, turn_count);
        Limit_cater->CatPlayerLimits(player);

        turn_count++;
    }

    // free all classes

    // delete core classes
    delete(setting_giver);
  
    // delete play classes
    delete(player);

    // delete city
    delete(city_astralith);
    delete(city_postblavn);
    delete(city_kinland);

}
