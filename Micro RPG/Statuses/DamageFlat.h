#pragma once

#include "Status.h"

class DamageFlat : public Status
{
public:
    DamageFlat 
    (
        int extra_flat_dmg_,
        int duration_ = default_duration
    ) :
        extra_flat_dmg(extra_flat_dmg_),
        Status(duration_, true)
    {}

    void apply(int& dmg) const;

    std::string status_name() const { return "flat dmg"; }
    std::string status_value() const;

protected:
    int extra_flat_dmg;

private:
    static const int default_duration = 1;
};

