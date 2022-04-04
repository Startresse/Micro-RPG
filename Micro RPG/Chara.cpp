#include "Chara.h"

void Chara::display_state() const
{
    std::cout << "[" << class_name() << "] | ";
    std::cout << "HP : " << HP << " | ";
    std::cout << "CD : " << current_cooldown;
    if (stunned)
        std::cout << " | STUNNED!";

    std::cout << std::endl;
}

void Chara::attack(Chara& c)
{
    std::cout << class_name() << " attacks " << c.class_name() << " for " << atk << " damage.\n";
    c.take_damage(atk);
}

void Chara::end_turn()
{
    // TODO multi turn stun ?
    stunned = false;
    current_cooldown = std::max(current_cooldown - 1, 0);
}

bool Chara::roll(float chance)
{
    return (static_cast<double>(rand()) / RAND_MAX) < chance;
}
