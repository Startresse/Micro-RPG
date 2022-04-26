#pragma once

#include "Status.h"

class DamageMultiplier : public Status
{
public:
    DamageMultiplier 
    (
        float damage_multiplier_,
        int duration_ = default_duration
    ) :
        damage_multiplier(damage_multiplier_),
        Status(duration_, true)
    {}

    void apply(int& dmg) const;
    float multiplier_value() const { return damage_multiplier; }

    std::string status_name() const { return "dmg mult"; }
    std::string status_value() const;

protected:
    float damage_multiplier;

private:
    static const int default_duration = 1;
};

