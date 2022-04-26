#include "DamageMultiplier.h"

#include <sstream>
#include <iomanip>

#include "Misc/Utility.h"

void DamageMultiplier::apply(int& dmg) const
{
    dmg = static_cast<int>(std::round(dmg * damage_multiplier));
}

std::string DamageMultiplier::status_value() const
{
    std::stringstream output;

    output << std::setprecision(2);
    output << "x" << damage_multiplier;

    return output.str();
}
