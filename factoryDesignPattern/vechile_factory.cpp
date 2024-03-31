#include "vechile_factory.hpp"

Vechile* Vechile_factory::getVechile(string vechileType)
{
    Vechile* vechile;
    if(vechileType =="car")
        vechile = new Car();
    return vechile;
}