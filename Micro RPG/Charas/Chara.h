#pragma once

#include <string>
#include <map>
#include <set>
#include <typeindex>
#include <stdexcept>

#include "Statuses/StatusType.h"

class Status;
class Team;

class Chara
{
public:
    /* Construction */

    Chara(int HP_, int atk_, int cooldown_, int skill_success_rate_);
    virtual ~Chara();


    /* Combat */

    void attack();
    void special_move();

    virtual void take_damage(int atk);
    void heal(int heal_amount);

    virtual void reset_target(Team* enemy_team, Team* ally_team);

    void end_turn();


    /* Status */

    // indirection that allows to recover the status for non stackable statuses
    template <typename t>
    const Status* has_status() const;

    bool is_stunned() const;
    bool is_on_CD() const;
    bool is_dead() const { return HP <= 0; }

    /// return true if target is OK
    bool has_good_target() const;

    int lost_hp() const { return max_HP - HP; }

    /* Display */

    void display_state() const;

    virtual std::string name() const = 0;

protected:
    /* Characteristics */

    int HP;
    int atk;
    int cooldown;
    // succes chance for 100 roll (ie % chance)
    int skill_success_rate;

    Chara* target;

    /* Combat */

    int attack_damage() const;
    void stun_target() const;
    void guard(Chara* c);
    virtual void skill() = 0;

    void add_status(Status* s);


    /* Display */

    virtual std::string class_name() const = 0;
    virtual std::string special_move_name() const = 0;

    void display_class_name() const;
    void display_HP() const;
    void display_statuses() const;

private:

    int max_HP;

    /* Combat */

    // chance between 0 and 1.
    // 0.2 means 20% chance of success, etc..
    bool roll_skill() const;


    /* Status */

    // Similar statuses would be stored in the same vector accessible by the status type
    std::map<statustype::type_index, std::set<Status*>> statuses;

    template <typename t>
    std::set<Status*> get_set() const { return get_set(typeid(t)); }
    std::set<Status*> get_set(const std::type_index& t) const;
};

template <typename t>
const Status* Chara::has_status() const
{
    for (const Status* s : get_set<t>())
    {
        if (s->is_active())
            return s;
    }
    
    return nullptr;
}
