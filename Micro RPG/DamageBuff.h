#pragma once

#include "Status.h"

class DamageBuff : public Status
{
public:
    DamageBuff
    (
        float damage_multiplier_ = default_damage_multiplier,
        int extra_flat_damage_ = default_extra_flat_damage,
        int duration_ = default_duration
    ) :
        damage_multiplier(damage_multiplier_),
        extra_flat_damage(extra_flat_damage_),
        Status(duration_, true) 
    {}

protected:
    float damage_multiplier;
    int extra_flat_damage;

private:
    static const int default_duration = 1;
    static const float default_damage_multiplier;
    static const int default_extra_flat_damage = 0;
};
