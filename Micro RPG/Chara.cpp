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

void Chara::attack(Chara& c)
{
    attack(c, atk);
}

void Chara::attack(Chara& c, int dmg)
{
    if (is_stunned())
    {
        std::cout << class_name() << " is stunned!\n";
        return;
    }

    std::cout << class_name() << " attacks " << c.class_name() << " for " << dmg << " damage.\n";
    c.take_damage(dmg);
}

void Chara::end_turn()
{
    stunned = false;
    current_cooldown = std::max(current_cooldown - 1, 0);
}

bool Chara::roll(float chance)
{
    return (static_cast<double>(rand()) / RAND_MAX) < chance;
}

void Chara::take_damage(int atk)
{
    HP -= atk;
}
