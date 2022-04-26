#include "DamageFlat.h"

#include <sstream>
#include <iomanip>

#include "Misc/Utility.h"

void DamageFlat::apply(int& dmg) const
{
    dmg += extra_flat_dmg;
}

std::string DamageFlat::status_value() const
{
    std::stringstream output;

    output << std::setprecision(2);
    output << (extra_flat_dmg > 0 ? "+" : "") << extra_flat_dmg;

    return output.str();
}
