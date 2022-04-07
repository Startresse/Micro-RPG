#pragma once

#include "Chara.h"

class Knight : public Chara
{
public:
    Knight() :
        Chara(default_HP, default_atk, default_cooldown, default_skill_success_rate),
        shield(default_shield)
    {}

    void skill();
    void take_damage(int atk);

    void end_turn();

    void attack();

    void display_state() const;

    std::string class_name() const { return "Knight"; }
    std::string special_move_name() const { return "CHARGE"; }

protected:
    int shield;

    bool double_damage = false;
    bool shield_just_broke = false;

private:
    // Gamedesign : does shield block a fullhit even when very low or does it behave just like extra HP?
    enum class shield_behaviour
    {
        ONLY_EXTRA_HP,
        FULL_BLOCK,
    };
    static const shield_behaviour sb = shield_behaviour::FULL_BLOCK;

    static const int default_HP = 20;
    static const int default_shield = 50;
    static const int default_atk = 5;
    static const int default_cooldown = 3;
    static const float default_skill_success_rate;
};

