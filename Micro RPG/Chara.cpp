#include "Chara.h"

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
    if (!check_target())
    {
        std::cout << class_name() << " has no target!\n";
        return;
    }

    if (is_stunned())
    {
        std::cout << class_name() << " is stunned!\n";
        return;
    }

    int dmg = attack_damage();
    target->take_damage(dmg);

    std::cout << class_name() << " attacks " << target->class_name() << " for " << dmg << " damage.\n";
}

void Chara::end_turn()
{
    stunned = false;
    current_cooldown = std::max(current_cooldown - 1, 0);

    turn_end();
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

/* DISPLAY */

void Chara::display_class_name() const
{
    std::cout << "[" << class_name() << "]";
}
void Chara::display_HP() const
{
    std::cout << " | HP: " << HP;
}
void Chara::display_CD() const
{
    std::cout << " | CD: " << current_cooldown;
}
void Chara::display_stunned() const
{
    if (stunned)
        std::cout << " | STUNNED!";
}

void Chara::display_state() const
{
    display_class_name();
    display_HP();
    display_CD();
    display_stunned();

    std::cout << std::endl;
}
