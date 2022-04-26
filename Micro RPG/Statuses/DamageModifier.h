#pragma once

#include "Status.h"

template<typename t>
class DamageModifier : public Status
{
public:
    DamageModifier(t modifier_, int duration_ = default_duration) :
        modifier(modifier_), Status(duration_, true) {}

    virtual void apply(int& dmg) const = 0;
    t value() const { return modifier; }

protected:
    t modifier;

private:
    static const int default_duration = 1;
};