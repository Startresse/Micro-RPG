#include "Orc.h"

void Orc::special_move()
{
    if (!check_target())
        return;

    std::cout << class_name() << " uses STUN : ";
    if (roll(0.20f))
    {
        stun(*target);
        std::cout << "SUCCESS!";
    }
    else
        std::cout << "FAILED!";
    std::cout << std::endl;

    current_cooldown = cooldown;
}

