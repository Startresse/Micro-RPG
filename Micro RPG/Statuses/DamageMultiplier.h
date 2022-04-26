#pragma once

#include "DamageModifier.h"

class DamageMultiplier : public DamageModifier<float> 
{
public:
    using DamageModifier<float>::DamageModifier;

    void apply(int& dmg) const;

    std::string status_name() const { return "dmg mult"; }
    std::string status_value() const;
};

