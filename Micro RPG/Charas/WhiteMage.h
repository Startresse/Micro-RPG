#pragma once

#include "CountableChara.h"

class WhiteMage : public CountableChara<WhiteMage>
{
public:
    WhiteMage();

    std::string class_name() const { return "White Mage"; }
    std::string special_move_name() const { return "HEAL"; }

protected:
    Chara* ally_target;
    
    void skill();
    void reset_target(Team* enemy_team, Team* ally_team);

private:
    static const int default_HP = 30;
    static const int default_atk = 3;
    static const int default_cooldown = 2;
    static const int default_skill_success_rate = 50;
};