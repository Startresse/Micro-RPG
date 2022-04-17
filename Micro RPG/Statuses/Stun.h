#pragma once

#include "Status.h"

class Stun : public Status
{
public:
    Stun(int duration = default_duration) : Status(duration, false) {}

    std::string status_name() const { return "stunned"; }

private:
    static const int default_duration = 1;
};
