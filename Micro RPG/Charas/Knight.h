#pragma once

#include "CountableChara.h"

class Knight : public CountableChara<Knight>
{
public:
    Knight();

    std::string class_name() const { return "Knight"; }
    std::string special_move_name() const { return "CHARGE"; }

protected:
    void skill();

private:
    static const int default_HP = 20;
    static const int default_shield = 50;
    static const int default_atk = 5;
    static const int default_cooldown = 3;
    static const int default_skill_success_rate = 60;
};

