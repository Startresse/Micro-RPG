#include "Knight.h"

#include "Statuses/DamageModifier.h"
#include "Statuses/Shield.h"

const float Knight::default_skill_success_rate = 0.60f;

Knight::Knight() :
    CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate)
{
    add_status(new Shield(default_shield));
}

void Knight::skill()
{
    add_status(new DamageModifier(2));
}
