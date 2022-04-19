#include "Shield.h"

#include <sstream>

void Shield::take_hit(int& dmg)
{
    if (shield_value == 0)
        return;

    shield_value = std::max(shield_value - dmg, 0);
    dmg = 0;
}

std::string Shield::status_name() const
{
    std::stringstream output;

    if (shield_value > 0)
        output << "shield: " << shield_value;
    else
        output << "shield broke and absorbed all the attack!";

    return output.str();
}
