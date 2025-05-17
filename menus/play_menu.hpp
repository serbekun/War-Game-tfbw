    #pragma once

    #include <iostream>
    #include <string>
    #include <limits>

    // include core
    #include "../core/class_setting.hpp"
    #include "../core/class_shower.hpp"

    // include play class
    #include "../classes/class_player.hpp"
    #include "../classes/class_city.hpp"
    
    using namespace std;
    
    void play_menu (int difficult) {

        // init value
        int *turn_count = new int;
        int *input = new int;


        // init core classes
        setting::setting_giver* setting_giver = new setting::setting_giver;
        core::Shower* shower = new core::Shower;


        // inti play classes
        player_use_classes::Player* player = new player_use_classes::Player(setting_giver, "unknown", difficult);
        
        int *city_name_num = new int;

        // create city
        class_city::City* city_astralith = new class_city::City(setting_giver->return_city_names(*city_name_num));
        (*city_name_num)++;
        class_city::City* city_test1 = new class_city::City(setting_giver->return_city_names(*city_name_num));
        (*city_name_num)++;
        class_city::City* city_test2 = new class_city::City(setting_giver->return_city_names(*city_name_num));
        (*city_name_num)++;
        class_city::City* city_test3 = new class_city::City(setting_giver->return_city_names(*city_name_num));
        delete(city_name_num);

        // add city neighbors
        
        // city astralith neighbors 
        city_astralith->AddNeighbor(city_test1);
        city_astralith->AddNeighbor(city_test2);
        
        // city test1 neighbors
        city_test1->AddNeighbor(city_astralith);
        city_test1->AddNeighbor(city_test2);
        
        // city test2 neighbors
        city_test2->AddNeighbor(city_astralith);
        city_test2->AddNeighbor(city_test1);
        city_test2->AddNeighbor(city_test3);

        // city test3 neighbors

        city_test3->AddNeighbor(city_test2);


        while (1) {

            shower->ShowActionForPlayer();
            cout << "type option of action what you want to do : ";
            cin >> *input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (*input)
            {
            case 1:
                player->ShowPositionForChoseWhereCanMove();
                player->MoveTOAnotherCity();
                break;
            
            default:
                break;
            }



            player->CalculateHungry(setting_giver, difficult, *turn_count);

            (*turn_count)++;
        }

        // clear variable
        delete(turn_count);

        // free all classes

        // delete core classes
        delete(setting_giver);
  
        // delete play classes
        delete(player);

        // delete city
        delete(city_astralith);
        delete(city_test1);
        delete(city_test2);
        delete(city_test3);


}