#include "vechile_factory.hpp"
#include "iostream"
using namespace std;

int main()
{
    string vechileType;
    cin>>vechileType;
    Vechile* vechile = Vechile_factory::getVechile(vechileType);
    vechile->createVechile();
    return 0;
}