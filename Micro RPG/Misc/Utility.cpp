#include "Utility.h"

#include <random>
#include <iostream>

bool Utility::roll(float succes_rate)
{
    return (static_cast<double>(rand()) / RAND_MAX) < succes_rate;
}


char Utility::input()
{
    std::cout << "\n> ";
    char n;
    std::cin >> n;

    return n;
}
