#include "Knight.h"

Knight::Knight()
{
    HP = 20;
    shield = 50;
    atk = 5;
    cooldown = 3;
}

// TODO remove parameter ?
void Knight::special_move(Chara& c)
{
    if (current_cooldown > 0)
        return;

    std::cout << "Knight uses CHARGE : ";
    if (roll(0.60f))
    {
        double_damage = true;
        std::cout << "SUCCESS";
    }
    else
        std::cout << "FAILED!";
    std::cout << std::endl;

    current_cooldown = cooldown;
}

void Knight::attack(Chara& c)
{
    int dmg = double_damage ? 2 * atk : atk;
    // if stunned cancel charge skill
    double_damage = false;

    if (!is_stunned())
    {
        std::cout << class_name() << " attacks " << c.class_name() << " for " << dmg << " damage.\n";
        c.take_damage(dmg);
    }
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
    }

    HP -= atk;
}

void Knight::display_state() const
{
    std::cout << "[" << class_name() << "]";
    std::cout << " | HP : " << HP;
    std::cout << " | shield : " << shield;
    std::cout << " | CD : " << current_cooldown;
    if (stunned)
        std::cout << " | STUNNED!";

    std::cout << std::endl;
}
