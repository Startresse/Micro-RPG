#pragma once

#include <iostream>

class Chara
{
public:
    Chara(int HP_, int atk_, int cooldown_, float skill_success_rate_)
        : HP(HP_), atk(atk_), cooldown(cooldown_), skill_success_rate(skill_success_rate_), target(nullptr) {}

    virtual void attack();
    void stun(Chara& c) const { c.stunned = true; }

    virtual void end_turn();

    bool is_dead() const { return HP <= 0; }
    bool is_stunned() const { return stunned; }

    void special_move();
    virtual void take_damage(int atk);

    virtual void display_state() const;

    virtual std::string class_name() const = 0;
    virtual std::string special_move_name() const = 0;

    // chance between 0 and 1.
    // 0.2 means 20% chance of success, etc..
    bool roll(float chance) const ;
    bool roll_skill() const;

    void set_target(Chara* c) { target = c; }
    // return true if target is OK
    bool check_target();
    bool is_on_CD() { return current_cooldown > 0; }

protected:
    int HP;
    int atk;
    int cooldown;
    float skill_success_rate;

    int current_cooldown = 0;
    bool stunned = false;

    void attack(int dmg);
    virtual void skill() = 0;

    Chara* target;
};

