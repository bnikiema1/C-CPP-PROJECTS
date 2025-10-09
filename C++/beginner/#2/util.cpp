#include <iostream>
#include <random>
#include "util.h"

using namespace std;

int randomRange(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution <> dis(min, max);

    return dis(gen);
}