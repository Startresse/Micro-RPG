#include "Knight.h"

#include "DamageModifier.h"

const float Knight::default_skill_success_rate = 0.60f;

void Knight::skill()
{
    add_status(new DamageModifier(2));
}

void Knight::take_damage(int dmg)
{
    take_hit(dmg);

    HP -= dmg;
}

void Knight::end_turn_extra()
{
    ShieldedUnit::end_turn();
}
