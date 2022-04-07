#pragma once

#include "Chara.h"

class Knight : public Chara
{
public:
    Knight() : Chara(20, 5, 3), shield(50) {}

    void special_move();
    void take_damage(int atk);

    void end_turn();

    void attack();

    void display_state() const;

    std::string class_name() const { return "Knight"; }

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
};

