#pragma once

#include <iostream>
#include <random>

using namespace std;

namespace utils {

class rng {

    public:
    rng() : gen(rd()) {}

    int GetRandomIntWithDiapason(int min, int max) {
        uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }

private:
    random_device rd;
    mt19937 gen;
};

}