#pragma once

#include <string>
#include <map>
#include <set>
#include <typeindex>
#include <stdexcept>

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
    bool is_stunned() const;

    void special_move();
    virtual void take_damage(int atk);

    void display_state() const;

    virtual std::string name() const = 0;

    void set_target(Chara* c);
    // return true if target is OK
    bool has_good_target() const;
    bool is_on_CD() { return current_cooldown > 0; }

protected:
    int HP;
    int atk;
    int cooldown;
    float skill_success_rate;

    int current_cooldown = 0;
    // TODO remove vector and use some better stuff to handle removal
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
    void display_CD() const;
    void display_statuses() const;

private:
    // Similar statuses would be stored in the same vector accessible by the status type
    std::map<std::type_index, std::set<Status*>> statuses;

    template <typename t>
    std::set<Status*> get_set() const;

    // chance between 0 and 1.
    // 0.2 means 20% chance of success, etc..
    bool roll_skill() const;
};

template <typename t>
std::set<Status*> Chara::get_set() const
{
    try
    {
        return statuses.at(typeid(t));
    }
    catch (const std::out_of_range&)
    {
        return std::set<Status*>();
    }
}
