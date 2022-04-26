#include "DamageMultiplier.h"

#include <sstream>
#include <iomanip>

void DamageMultiplier::apply(int& dmg) const
{
    dmg = static_cast<int>(std::round(dmg * modifier));
}

std::string DamageMultiplier::status_value() const
{
    std::stringstream output;

    output << std::setprecision(2);
    output << "x" << modifier;

    return output.str();
}
