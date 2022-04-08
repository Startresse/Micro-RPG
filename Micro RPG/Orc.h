#pragma once

#include "Chara.h"

class Orc : public Chara
{
public:
    Orc() :
        Chara(default_HP, default_atk, default_cooldown, default_skill_success_rate)
    {}

    std::string class_name() const { return "Orc"; }
    std::string special_move_name() const { return "STUN"; }

protected:
    void skill();

private:
    static const int default_HP = 60;
    static const int default_atk = 8;
    static const int default_cooldown = 5;
    static const float default_skill_success_rate;

};

