#pragma once

#include "CountableChara.h"

class Orc : public CountableChara<Orc>
{
public:
    Orc() :
        CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate)
    {}

    std::string class_name() const { return "Orc"; }
    std::string special_move_name() const { return "STUN"; }

protected:
    void skill() { stun_target(); }

private:
    static const int default_HP = 60;
    static const int default_atk = 8;
    static const int default_cooldown = 5;
    static const int default_skill_success_rate = 20;
};

