#include "Orc.h"

Orc::Orc()
{
    HP = 60;
    atk = 8;
    cooldown = 5;
}

void Orc::special_move(Chara& c)
{
    if (current_cooldown > 0)
        return;

    if (roll(0.20f))
        stun(c);

    current_cooldown = cooldown;
}

void Orc::take_damage(int atk)
{
    HP -= atk;
}

