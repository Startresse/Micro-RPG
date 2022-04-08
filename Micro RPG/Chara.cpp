#include "Chara.h"

#include <string>

#include "Utility.h"

std::string Chara::name() const
{
    return class_name() + " " + std::to_string(ID);
}

void Chara::special_move()
{
    if (is_on_CD())
    {
        std::cout << name() << " special move is on CD.\n";
        return;
    }

    current_cooldown = cooldown;

    bool success = roll_skill();

    if (success)
        skill();

    std::cout << name() << " uses " << special_move_name() << " : ";
    std::cout << (success ? " SUCCESS!" : "FAIL!") << "\n";
}

void Chara::attack()
{
    if (!has_good_target())
    {
        std::cout << name() << " has no target!\n";
        return;
    }

    if (is_stunned())
    {
        std::cout << name() << " is stunned!\n";
        return;
    }

    int dmg = attack_damage();
    target->take_damage(dmg);

    std::cout << name() << " attacks " << target->name() << " for " << dmg << " damage.\n";
}

void Chara::end_turn()
{
    stunned = false;
    current_cooldown = std::max(current_cooldown - 1, 0);

    turn_end();
}

bool Chara::roll_skill() const
{
    return Utility::roll(skill_success_rate);
}

void Chara::take_damage(int atk)
{
    HP -= atk;
}

void Chara::set_target(Chara* c)
{
    target = c;
    std::cout << name() << " targets " << c->name() << ".\n";
}

bool Chara::has_good_target()
{
    if (target == nullptr or target->is_dead())
        return false;

    return true;
}

/* DISPLAY */

void Chara::display_class_name() const
{
    std::cout << "[" << name() << "]";
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
