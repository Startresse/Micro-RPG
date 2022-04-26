#include "Chara.h"

#include <iostream>
#include <string>
#include <vector>

#include "Misc/Utility.h"
#include "Logic/Team.h"
#include "Statuses/Cooldown.h"
#include "Statuses/Stun.h"
#include "Statuses/DamageMultiplier.h"
#include "Statuses/DamageFlat.h"
#include "Statuses/Shield.h"
#include "Statuses/Guard.h"


/* Construction */

Chara::Chara(int HP_, int atk_, int cooldown_, float skill_success_rate_) :
    HP(HP_),
    max_HP(HP),
    atk(atk_),
    cooldown(cooldown_),
    skill_success_rate(skill_success_rate_),
    target(nullptr)
{}

Chara::~Chara()
{
    for (auto& status_element : statuses)
    {
        for (Status* s : status_element.second)
            delete s;
    }
}


/* Combat */

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

void Chara::take_damage(int atk)
{
    // Redirect attack to guardian
    if (const Status* s = has_status<Guard>())
    {
        Chara* guardian = static_cast<const Guard*>(s)->get_guardian();

        // Guardian can't have a guardian to prevent infinite loop
        if (!guardian->has_status<Guard>())
        {
            guardian->take_damage(atk);
            return;
        }
    }

    // TODO shield stacking
    for (Status* s : get_set<Shield>())
    {
        Shield* shield = static_cast<Shield*>(s);
        if (shield->is_active())
            shield->take_hit(atk);
    }

    HP -= atk;
}

// TODO smart targeting
void Chara::reset_target(Team* enemy_team, Team* ally_team)
{
    if (target && !target->is_dead())
        return;

    Chara* target = enemy_team->get_random_alive_chara();
    if (target)
    {
        this->target = target;
        std::cout << name() << " now targets " << target->name() << ".\n";
    }
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

void Chara::stun_target() const
{
    if (!has_good_target())
        return;

    target->add_status(new Stun());
}

void Chara::guard(Chara* c)
{
    c->add_status(new Guard(this));
}

void Chara::heal(int amount)
{
    HP = std::min(HP + amount, max_HP);
}

void Chara::add_status(Status* s)
{
    statuses[typeid(*s)].insert(s);
}

bool Chara::roll_skill() const
{
    return Utility::roll(skill_success_rate);
}


/* Status */

inline bool Chara::is_stunned() const
{
    return has_status<Stun>();
}

inline bool Chara::is_on_CD() const
{
    return has_status<Cooldown>();
}

bool Chara::has_good_target() const
{
    if (target == nullptr or target->is_dead())
        return false;

    return true;
}

std::set<Status*> Chara::get_set(const std::type_index& t) const
{
    try
    {
        return statuses.at(t);
    }
    catch (const std::out_of_range&)
    {
        return std::set<Status*>();
    }
}



/* DISPLAY */

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
    for (const auto& status_element : statuses)
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

        if (t == typeid(DamageMultiplier))
        {
            float multiplier = 1.f;
            for (const Status* s : s_set)
                multiplier *= static_cast<const DamageMultiplier*>(s)->value();
            std::cout << " x" << multiplier;
            continue;
        }

        if (t == typeid(DamageFlat))
        {
            int flat_modifier = 0;
            for (const Status* s : s_set)
                flat_modifier += static_cast<const DamageFlat*>(s)->value();
            std::cout << (flat_modifier > 0 ? " +" : " ") << flat_modifier;
            continue;
        }

        // default Status display behaviour
        std::cout << " : ";
        for (const Status* s : s_set)
            std::cout << s->status_value();

    }
}
