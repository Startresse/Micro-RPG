#pragma once

#include "Status.h"

// split into damage multiplier and damage flat
class DamageModifier : public Status
{
public:
    DamageModifier
    (
        float damage_multiplier_ = default_damage_multiplier,
        int extra_flat_damage_ = default_extra_flat_damage,
        int duration_ = default_duration
    ) :
        damage_multiplier(damage_multiplier_),
        extra_flat_damage(extra_flat_damage_),
        Status(duration_, true)
    {}

    void apply(int& dmg) const;

    std::string status_name() const { return "damage modificator"; }
    std::string status_value() const;

protected:
    float damage_multiplier;
    int extra_flat_damage;

private:
    static const int default_duration = 1;
    static const float default_damage_multiplier;
    static const int default_extra_flat_damage = 0;
};

