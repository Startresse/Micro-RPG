#include "ShieldedUnit.h"

#include <iostream>

void ShieldedUnit::take_hit(int &dmg)
{
    if (shield_value == 0)
        return;

    shield_value = std::max(shield_value - dmg, 0);
    dmg = 0;

    if (shield_value == 0)
        shield_just_broke = true;
}

void ShieldedUnit::end_turn()
{
    shield_just_broke = false;
}

void ShieldedUnit::display_shield() const
{
    if (shield_value > 0)
        std::cout << " | shield: " << shield_value;
    if (shield_just_broke)
        std::cout << " | SHIELD BROKE AND ABSORBED ALL THE ATTACK!";
}
