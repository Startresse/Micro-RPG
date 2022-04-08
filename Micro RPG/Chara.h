#pragma once

#include <iostream>
#include <vector>

#include "Status.h"

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

    ~Chara();

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
    std::vector<Status*> statuses = std::vector<Status*>(0);

    void stun_target() const;
    void stun();

    virtual int attack_damage() { return atk; }
    virtual void skill() = 0;
    virtual void end_turn_extra() {}

    Chara* target;

    virtual std::string class_name() const = 0;
    virtual std::string special_move_name() const = 0;

    void display_class_name() const;
    void display_HP() const;
    void display_CD() const;
    void display_stunned() const;

private:
    // chance between 0 and 1.
    // 0.2 means 20% chance of success, etc..
    bool roll_skill() const;
};

