#pragma once

#include "Status.h"

class Shield : public Status
{
public:
    Shield(int shield_value_, int duration_ = default_duration) :
        shield_value(shield_value_),
        Status(duration_, true)
    {}

    void take_hit(int& dmg);
    bool has_expired() const { return Status::has_expired() || shield_value == 0; }

    std::string status_name() const;

protected:
    int shield_value;

private:
    static const int default_duration = -1;
};

