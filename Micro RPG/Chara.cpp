#include "Chara.h"

void Chara::display_state() const
{
    std::cout << "[" << class_name() << "]";
    std::cout << " | HP: " << HP;
    std::cout << " | CD: " << current_cooldown;
    if (stunned)
        std::cout << " | STUNNED!";

    std::cout << std::endl;
}

void Chara::attack()
{
    attack(atk);
}

void Chara::attack(int dmg)
{
    if (!check_target())
        return;

    if (is_stunned())
    {
        std::cout << class_name() << " is stunned!\n";
        return;
    }

    std::cout << class_name() << " attacks " << target->class_name() << " for " << dmg << " damage.\n";
    target->take_damage(dmg);
}

void Chara::end_turn()
{
    stunned = false;
    current_cooldown = std::max(current_cooldown - 1, 0);
}

bool Chara::roll(float chance) const
{
    return (static_cast<double>(rand()) / RAND_MAX) < chance;
}

void Chara::take_damage(int atk)
{
    HP -= atk;
}

bool Chara::check_target()
{
    if (target == nullptr or target->is_dead())
    {
        std::cout << "ERROR: " << class_name() << " NEEDS RETARGETING" << std::endl;
        return false;
    }
    return true;
}
