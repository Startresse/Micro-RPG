#pragma once

#include "Status.h"

class Chara;

class Guard : public Status
{
public:
    Guard(Chara* guardian_, int duration_ = default_duration) :
        guardian(guardian_),
        Status(duration_)
    {}

    Chara* get_guardian() const { return guardian; }

    std::string status_name() const { return "guard"; }
    std::string status_value() const;

protected:
    Chara* guardian;

private:
    static const int default_duration = 1;
};