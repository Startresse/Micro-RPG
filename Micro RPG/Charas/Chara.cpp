#include "Chara.h"

#include <iostream>
#include <string>
#include <vector>

#include "Misc/Utility.h"
#include "Statuses/Stun.h"
#include "Statuses/DamageModifier.h"
#include "Statuses/Shield.h"

Chara::~Chara()
{
    for (Status* s : statuses)
        delete s;
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
    std::cout << (success ? "SUCCESS!" : "FAIL!") << "\n";
}

bool Chara::is_stunned() const
{
    for (const Status* s : statuses)
    {
        const Stun* stun = dynamic_cast<const Stun*>(s);
        if (stun && stun->is_active())
            return true;
    }

    return false;
}

void Chara::add_status(Status* s)
{
    statuses.insert(s);
}

void Chara::stun_target() const
{
    if (!has_good_target())
        return;

    target->stun();
}

void Chara::stun()
{
    statuses.insert(new Stun());
}

int Chara::attack_damage() const
{
    int dmg = atk;
    for (const Status* s : statuses)
    {
        const DamageModifier* dm = dynamic_cast<const DamageModifier*>(s);
        if (dm && dm->is_active())
            dm->apply(dmg);
    }

    return dmg;
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

// TODO check dead + check dead for display
void Chara::end_turn()
{
    std::vector<std::set<Status*>::iterator> to_delete;
    for (std::set<Status*>::iterator it = statuses.begin(); it != statuses.end(); ++it)
    {
        Status* s = *it;
        s->end_turn();

        if (s->has_expired())
            to_delete.push_back(it);
    }
    for (const auto it : to_delete)
        statuses.erase(it);

    current_cooldown = std::max(current_cooldown - 1, 0);
}

bool Chara::roll_skill() const
{
    return Utility::roll(skill_success_rate);
}

void Chara::take_damage(int atk)
{
    for (Status* s : statuses)
    {
        Shield* shield = dynamic_cast<Shield*>(s);
        if (shield && shield->is_active())
            shield->take_hit(atk);
    }

    HP -= atk;
}

void Chara::set_target(Chara* c)
{
    if (!c)
        return;

    target = c;
    std::cout << name() << " now targets " << c->name() << ".\n";
}

bool Chara::has_good_target() const
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
void Chara::display_statuses() const
{
    for (const Status* s : statuses)
        std::cout << " | " << s->status_name();
}

void Chara::display_state() const
{
    if (is_dead())
    {
        display_class_name();
        std::cout << " is dead.\n";
        return;
    }

    display_class_name();
    display_HP();
    display_CD();
    display_statuses();

    std::cout << std::endl;
}
