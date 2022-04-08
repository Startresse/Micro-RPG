#pragma once

class Status
{
public:
    Status(int duration, bool is_a_buff_) : remaining_duration(duration), is_a_buff(is_a_buff_) {}

    virtual void end_turn();

    bool is_active() const;
    bool is_buff() const { return is_a_buff; }
    bool is_debuff() const { return !is_buff(); }

    virtual void display() const = 0;

private:
    int remaining_duration;

    bool is_a_buff;
};

