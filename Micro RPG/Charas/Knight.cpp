#include "Knight.h"

#include "Statuses/DamageMultiplier.h"
#include "Statuses/Shield.h"

Knight::Knight() :
    CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate)
{
    add_status(new Shield(default_shield));
}

void Knight::skill()
{
    add_status(new DamageMultiplier(2.f));
}
