#pragma once

#include <string>

class Status
{
public:
    Status(int duration) : remaining_duration(duration) {}
    virtual ~Status() {}

    virtual void end_turn();

    bool is_active() const;
    virtual bool has_expired() const { return remaining_duration == 0; }

    virtual std::string status_name() const = 0;
    virtual std::string status_value() const = 0;

protected:
    int remaining_duration;
};

