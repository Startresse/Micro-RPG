#pragma once

#include "Status.h"

class Cooldown : public Status
{
public:
    using Status::Status;

    std::string status_name() const { return "CD"; }
    std::string status_value() const { return std::to_string(remaining_duration); }
};

