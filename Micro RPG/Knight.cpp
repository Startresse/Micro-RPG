#include "Knight.h"

const float Knight::default_skill_success_rate = 0.60f;

void Knight::skill()
{
    double_damage = true;
}

void Knight::attack()
{
    if (!check_target())
        return;

    int dmg = double_damage ? 2 * atk : atk;

    Chara::attack(dmg);
}

void Knight::take_damage(int atk)
{
    if (shield >= atk)
    {
        shield -= atk;
        return;
    }

    if (shield)
    {
        switch (sb)
        {
        case shield_behaviour::ONLY_EXTRA_HP:
            atk -= shield;
            break;
        case shield_behaviour::FULL_BLOCK:
            atk = 0;
            break;
        default:
            break;
        }
        shield = 0;
        shield_just_broke = true;
    }

    HP -= atk;
}

void Knight::end_turn()
{
    double_damage = false;
    shield_just_broke = false;
    Chara::end_turn();
}

void Knight::display_state() const
{
    std::cout << "[" << class_name() << "]";
    std::cout << " | HP: " << HP;
    if (shield > 0)
        std::cout << " | shield: " << shield;
    std::cout << " | CD: " << current_cooldown;
    if (shield_just_broke)
        std::cout << " | SHIELD BROKE AND ABSORBED ALL THE ATTACK!";
    if (stunned)
        std::cout << " | STUNNED!";
    if (double_damage)
        std::cout << " | BUFFED!";

    std::cout << std::endl;
}
