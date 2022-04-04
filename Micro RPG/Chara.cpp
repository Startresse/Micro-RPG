#include "Chara.h"


void Chara::display_state() const
{
    std::cout << "[" << class_name() << "] | ";
    std::cout << "HP : " << HP;
    std::cout << "CD : " << current_cooldown;
}
