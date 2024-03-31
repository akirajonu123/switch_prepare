#include <iostream>
#include "car.hpp"
#include <string.h>

using namespace std;


int main()
{
    string vechileType;
    cin>>vechileType;
    Vechile* temp;

    if(vechileType == "car")
    {
        temp = new Car();
    }
    temp->createVechile();

}