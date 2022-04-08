#include "Knight.h"

const float Knight::default_skill_success_rate = 0.60f;

void Knight::skill()
{
    double_damage = true;
}

int Knight::attack_damage()
{
    return double_damage ? 2 * atk : atk;
}

void Knight::take_damage(int dmg)
{
    take_hit(dmg);

    HP -= dmg;
}

void Knight::end_turn_extra()
{
    double_damage = false;
    ShieldedUnit::end_turn();
}


/* DISPLAY */
void Knight::display_buffed() const
{
    if (double_damage)
        std::cout << " | DOUBLE DAMAGE!";
}
