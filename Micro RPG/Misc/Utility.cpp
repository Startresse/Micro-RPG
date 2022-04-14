#include "Utility.h"

#include <iostream>

std::random_device seed;
std::mt19937 Utility::engine(seed());

auto Utility::random_value()
{
    return engine();
}

int Utility::random_value(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(engine);
}

bool Utility::roll(float succes_rate)
{
    return (static_cast<double>(engine()) / engine.max()) < succes_rate;
}


char Utility::input()
{
    std::cout << "\n> ";
    char n;
    std::cin >> n;

    return n;
}
