#pragma once

#include "DamageModifier.h"

class DamageFlat : public DamageModifier<int> 
{
public:
    using DamageModifier<int>::DamageModifier;

    void apply(int& dmg) const;

    std::string status_name() const { return "flat dmg"; }
    std::string status_value() const;
};

