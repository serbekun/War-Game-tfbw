#pragma once

#include <iostream>
#include <limits>

using namespace std;

int GetDifficult() 
{

    int input;

    cout << "----------------------------------------------" << endl;
    cout << "type what difficult you want to play" << endl;
    cout << "1. beginner" << endl;
    cout << "2. easy" << endl;
    cout << "3. normal" << endl;
    cout << "4. medium" << endl;
    cout << "5. hard" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "type number of difficult : ";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;

}