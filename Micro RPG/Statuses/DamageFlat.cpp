#include "DamageFlat.h"

void DamageFlat::apply(int& dmg) const
{
    dmg += modifier;
}

std::string DamageFlat::status_value() const
{
    return (modifier > 0 ? "+" : "") + modifier;
}
