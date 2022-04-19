#pragma once

#include <string>

class Status
{
public:
    Status(int duration, bool is_a_buff_) : remaining_duration(duration), is_a_buff(is_a_buff_) {}
    virtual ~Status() {}

    virtual void end_turn();

    bool is_active() const;
    virtual bool has_expired() const { return remaining_duration == 0; }
    bool is_buff() const { return is_a_buff; }
    bool is_debuff() const { return !is_buff(); }

    virtual std::string status_name() const = 0;
    virtual std::string status_value() const = 0;

private:
    int remaining_duration;

    // TODO handle both buff and debuff
    bool is_a_buff;
};

