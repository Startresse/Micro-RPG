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

void Chara::special_move()
{
    if (is_on_CD())
    {
        std::cout << class_name() << " special move is on CD.\n";
        return;
    }

    current_cooldown = cooldown;

    bool success = roll_skill();

    if (success)
        skill();

    std::cout << class_name() << " uses " << special_move_name() << " : ";
    std::cout << (success ? " SUCCESS!" : "FAIL!") << "\n";
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

bool Chara::roll_skill() const
{
    return roll(skill_success_rate);
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
