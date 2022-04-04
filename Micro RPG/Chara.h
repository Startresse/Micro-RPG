#pragma once

#include <iostream>

class Chara
{
public:
    void attack(Chara& c) { c.take_damage(atk); }

    bool is_dead() const { return HP <= 0; }

    virtual void special_move(Chara& c) = 0;
    virtual void take_damage(int atk) = 0;

    virtual void display_state() const;

    virtual std::string class_name() const = 0;

private:
    int HP;
    int atk;
    int cooldown;
    int current_cooldown;

};

