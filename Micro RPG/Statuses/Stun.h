#pragma once

#include "Status.h"

class Stun : public Status
{
public:
    Stun(int duration = default_duration) : Status(duration) {}

    std::string status_name() const { return "stunned"; }
    std::string status_value() const { return ""; };

private:
    static const int default_duration = 1;
};

