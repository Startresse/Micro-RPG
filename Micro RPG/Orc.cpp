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

    std::cout << "Orc uses STUN : ";
    if (roll(0.20f))
    {
        stun(c);
        std::cout << "SUCCESS";
    }
    else
        std::cout << "FAILED !";
    std::cout << std::endl;

    current_cooldown = cooldown;
}

void Orc::take_damage(int atk)
{
    HP -= atk;
}

