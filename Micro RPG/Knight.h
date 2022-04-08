#pragma once

#include "CountableChara.h"
#include "ShieldedUnit.h"

class Knight : public CountableChara<Knight>, public ShieldedUnit
{
public:
    Knight() :
        CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate),
        ShieldedUnit(default_shield)
    {}

    void take_damage(int atk);

    //split woth chara
    std::string class_name() const { return "Knight"; }
    std::string special_move_name() const { return "CHARGE"; }

protected:
    bool double_damage = false;

    int attack_damage();
    void skill();
    void end_turn_extra();

    void display_state_extra() const;

    // display
    void display_buffed() const;

private:
    static const int default_HP = 20;
    static const int default_shield = 50;
    static const int default_atk = 5;
    static const int default_cooldown = 3;
    static const float default_skill_success_rate;
};

