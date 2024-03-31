#ifndef vechile_factory_hpp
#define vechile_factory_hpp
#endif

#include "car.hpp"
#include <string.h>
#include <iostream>

using namespace std;

class Vechile_factory { 
    public:
    static Vechile* getVechile(string vechileType);

};