#pragma once

#include "CountableChara.h"

class Knight : public CountableChara<Knight>
{
public:
    Knight() :
        CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate),
        shield(default_shield)
    {}

    void take_damage(int atk);

    void display_state() const;

    //split woth chara
    std::string class_name() const { return "Knight"; }
    std::string special_move_name() const { return "CHARGE"; }

protected:
    int shield;

    bool double_damage = false;
    bool shield_just_broke = false;

    int attack_damage();
    void skill();
    void turn_end();

    // display
    void display_shield() const;
    void display_shield_broke() const;
    void display_buffed() const;

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

