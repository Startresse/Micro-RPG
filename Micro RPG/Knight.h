#pragma once

#include "Chara.h"

class Knight : public Chara
{
public:
    Knight();

    void special_move(Chara& c);
    void take_damage(int atk);

    void attack(Chara& c);

    void display_state() const;

    std::string class_name() const { return "Knight"; }

protected:
    int shield;

    bool double_damage = false;

private:
    // Gamedesign : does shield block a fullhit even when very low or does it behave just like extra HP?
    static enum class shield_behaviour
    {
        ONLY_EXTRA_HP,
        FULL_BLOCK,
    };
    static const shield_behaviour sb = shield_behaviour::FULL_BLOCK;
};

