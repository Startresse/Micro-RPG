#pragma once

#include <string>
#include <map>
#include <set>
#include <typeindex>
#include <stdexcept>

#include "Statuses/StatusType.h"

class Status;

class Chara
{
public:
    Chara(int HP_, int atk_, int cooldown_, float skill_success_rate_) :
        HP(HP_),
        atk(atk_),
        cooldown(cooldown_),
        skill_success_rate(skill_success_rate_),
        target(nullptr)
    {}

    virtual ~Chara();

    void attack();

    void end_turn();

    bool is_dead() const { return HP <= 0; }

    // indirection that allows to recover the status for non stackable statuses
    template <typename t>
    const Status* has_status() const;

    bool is_stunned() const;
    bool is_on_CD() const;

    void special_move();
    virtual void take_damage(int atk);

    void display_state() const;

    virtual std::string name() const = 0;

    void set_target(Chara* c);
    /// return true if target is OK
    bool has_good_target() const;

protected:
    int HP;
    int atk;
    int cooldown;
    float skill_success_rate;

    void add_status(Status* s);

    void stun_target() const;
    void stun();

    int attack_damage() const;
    virtual void skill() = 0;

    Chara* target;

    virtual std::string class_name() const = 0;
    virtual std::string special_move_name() const = 0;

    void display_class_name() const;
    void display_HP() const;
    void display_statuses() const;

private:
    // Similar statuses would be stored in the same vector accessible by the status type
    std::map<statustype::type_index, std::set<Status*>> statuses;

    template <typename t>
    std::set<Status*> get_set() const { return get_set(typeid(t)); }
    std::set<Status*> get_set(const std::type_index& t) const;

    // chance between 0 and 1.
    // 0.2 means 20% chance of success, etc..
    bool roll_skill() const;
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
