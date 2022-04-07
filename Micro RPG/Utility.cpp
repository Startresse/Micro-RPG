#include "Utility.h"

#include <random>

bool Utility::roll(float succes_rate)
{
    return (static_cast<double>(rand()) / RAND_MAX) < succes_rate;
}
