#include "Knight.h"

const float Knight::default_skill_success_rate = 0.60f;

void Knight::skill()
{
    double_damage = true;
}

int Knight::attack_damage()
{
    return double_damage ? 2 * atk : atk;
}

void Knight::take_damage(int dmg)
{
    if (shield)
    {
        int tmp_shield_value = shield;
        shield = std::max(shield - dmg, 0);

        switch (sb)
        {
        case shield_behaviour::ONLY_EXTRA_HP:
            dmg -= tmp_shield_value;
            break;
        case shield_behaviour::FULL_BLOCK:
            dmg = 0;
            break;
        default:
            break;
        }

        if (shield == 0)
            shield_just_broke = true;
    }

    HP -= dmg;
}

void Knight::turn_end()
{
    double_damage = false;
    shield_just_broke = false;
}


/* DISPLAY */

void Knight::display_shield() const
{
    if (shield > 0)
        std::cout << " | shield: " << shield;
}
void Knight::display_shield_broke() const
{
    if (shield_just_broke)
        std::cout << " | SHIELD BROKE AND ABSORBED ALL THE ATTACK!";
}
void Knight::display_buffed() const
{
    if (double_damage)
        std::cout << " | BUFFED!";
}

void Knight::display_state_s() const
{
    display_class_name();
    display_HP();
    display_shield();
    display_CD();
    display_shield_broke();
    display_stunned();
    display_buffed();
}
