#include "Chara.h"

#include <iostream>
#include <string>
#include <vector>

#include "Misc/Utility.h"
#include "Statuses/Cooldown.h"
#include "Statuses/Stun.h"
#include "Statuses/DamageMultiplier.h"
#include "Statuses/DamageFlat.h"
#include "Statuses/Shield.h"

Chara::~Chara()
{
    for (auto status_element : statuses)
    {
        for (Status* s : status_element.second)
            delete s;
    }
}

void Chara::special_move()
{
    if (is_on_CD())
    {
        std::cout << name() << " special move is on CD.\n";
        return;
    }

    add_status(new Cooldown(cooldown, false));

    bool success = roll_skill();

    if (success)
        skill();

    std::cout << name() << " uses " << special_move_name() << " : ";
    std::cout << (success ? "SUCCESS!" : "FAIL!") << "\n";
}

inline bool Chara::is_on_CD() const
{
    return has_status<Cooldown>();
}

inline bool Chara::is_stunned() const
{
    return has_status<Stun>();
}

void Chara::add_status(Status* s)
{
    statuses[typeid(*s)].insert(s);
}

void Chara::stun_target() const
{
    if (!has_good_target())
        return;

    target->stun();
}

void Chara::stun()
{
    add_status(new Stun());
}

int Chara::attack_damage() const
{
    int dmg = atk;

    for (const Status* s : get_set<DamageMultiplier>())
    {
        const DamageMultiplier* dm = static_cast<const DamageMultiplier*>(s);
        if (dm->is_active())
            dm->apply(dmg);
    }

    for (const Status* s : get_set<DamageFlat>())
    {
        const DamageFlat* flat = static_cast<const DamageFlat*>(s);
        if (flat->is_active())
            flat->apply(dmg);
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

void Chara::end_turn()
{
    for (auto& statuses_elem : statuses)
    {
        auto& set = statuses_elem.second;

        for (auto it = set.begin(); it != set.end(); )
        {
            Status* s = *it;
            s->end_turn();

            if (s->has_expired())
            {
                it = set.erase(it);
                delete s;
            }
            else
                ++it;
        }
    }
}

bool Chara::roll_skill() const
{
    return Utility::roll(skill_success_rate);
}

void Chara::take_damage(int atk)
{
    for (Status* s : get_set<Shield>())
    {
        Shield* shield = static_cast<Shield*>(s);
        if (shield->is_active())
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
    if (const Status* s = has_status<Shield>())
    {
        const Shield* shield = static_cast<const Shield*>(s);
        std::cout << " (" << shield->status_value() << ")";
    }
}
void Chara::display_statuses() const
{
    for (const auto status_element : statuses)
    {
        const std::set<Status*>& s_set = status_element.second;
        if (s_set.size() == 0)
            continue;

        const Status* first_s = *(s_set.begin());
        std::type_index t = typeid(*first_s);

        // skip shields for display
        if (t == typeid(Shield))
            continue;

        std::cout << " | " << first_s->status_name();

        // only display "stunned" when stunned
        if (t == typeid(Stun))
            continue;

        std::cout << " : ";
        for (const Status* s : status_element.second)
        {
            std::cout << s->status_value();
        }
    }
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
    display_statuses();

    std::cout << std::endl;
}
