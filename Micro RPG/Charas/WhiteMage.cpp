#include "WhiteMage.h"

#include <iostream>

#include "Logic/Team.h"

WhiteMage::WhiteMage() :
    ally_target(nullptr),
    CountableChara(default_HP, default_atk, default_cooldown, default_skill_success_rate)
{}

void WhiteMage::skill()
{
    if (ally_target != nullptr && !ally_target->is_dead())
        ally_target->heal(10);
}

void WhiteMage::reset_target(Team* enemy_team, Team* ally_team)
{
    Chara::reset_target(enemy_team, ally_team);

    Chara* target = ally_team->get_most_damaged_chara();
    if (target)
    {
        Chara* old_target = ally_target;
        if (old_target != target)
            std::cout << name() << " now targets " << target->name() << " to heal.\n";

        ally_target = target;
    }
}
