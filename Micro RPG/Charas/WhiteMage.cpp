#include "WhiteMage.h"

const float WhiteMage::default_skill_success_rate = 0.50f;

WhiteMage::WhiteMage() :
    ally_target(nullptr),
    CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate)
{}

void WhiteMage::skill()
{
    if (ally_target != nullptr && !ally_target->is_dead())
        ally_target->heal(10);
}
