#include "Knight.h"

void Knight::special_move()
{
    std::cout << class_name() << " uses CHARGE : ";

    if (roll(0.60f))
    {
        double_damage = true;
        std::cout << "SUCCESS!";
    }
    else
        std::cout << "FAILED!";
    std::cout << std::endl;

    current_cooldown = cooldown;
}

void Knight::attack()
{
    if (!check_target())
        return;

    int dmg = double_damage ? 2 * atk : atk;
    double_damage = false;

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
