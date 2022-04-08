#include "DamageModifier.h"

#include "Utility.h"

const float DamageModifier::default_damage_multiplier = 2.f;

std::string DamageModifier::status_name() const
{
    std::string output;

    output += "damage buffed:";

    bool dmg_display = abs(damage_multiplier - 1.0f) < Utility::epsilon;
    if (dmg_display)
        output += " x" + std::to_string(damage_multiplier);

    if (extra_flat_damage > 0)
    {
        output += (dmg_display ? "|" : "");
        output += ((extra_flat_damage > 0) ? " + " : " ");
        output += std::to_string(extra_flat_damage);
    }

    return output;
}
