#include "DamageModifier.h"

#include <sstream>
#include <iomanip>

#include "Misc/Utility.h"

const float DamageModifier::default_damage_multiplier = 2.f;

void DamageModifier::apply(int& dmg) const
{
    dmg = static_cast<int>(std::round(dmg * damage_multiplier)) + extra_flat_damage;
}

std::string DamageModifier::status_name() const
{
    std::stringstream output;

    output << std::setprecision(2);
    output << "damage modificator:";

    bool dmg_display = abs(damage_multiplier - 1.0f) > Utility::epsilon;
    if (dmg_display)
        output << " x" << damage_multiplier;

    if (extra_flat_damage != 0)
    {
        output << ((extra_flat_damage > 0) ? " + " : " ");
        output << extra_flat_damage;
    }

    return output.str();
}
