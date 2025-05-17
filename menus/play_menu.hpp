    #pragma once

    #include <iostream>
    #include <string>

    // include core
    #include "../core/class_setting.hpp"

    // include play class
    #include "../classes/class_player.hpp"
    #include "../classes/class_city.hpp"
    
    using namespace std;
    
    void play_menu (int difficult) {

        setting::setting_giver* setting_giver = new setting::setting_giver;


        player_use_classes::Player* player = new player_use_classes::Player(setting_giver, "unknown", difficult);
        
        int *city_name_num = new int;

        class_city::City* city_astralith = new class_city::City(setting_giver->return_city_names(*city_name_num));
        (*city_name_num)++;
        class_city::City* city_test1 = new class_city::City(setting_giver->return_city_names(*city_name_num));
        (*city_name_num)++;
        class_city::City* city_test2 = new class_city::City(setting_giver->return_city_names(*city_name_num));
        (*city_name_num)++;
        class_city::City* city_test3 = new class_city::City(setting_giver->return_city_names(*city_name_num));

        while (1) {


            break;

        }

        // free all classes
        delete(setting_giver);
        
        delete(player);

        delete(city_name_num);
        
        delete(city_astralith);
        delete(city_test1);
        delete(city_test2);
        delete(city_test3);


}