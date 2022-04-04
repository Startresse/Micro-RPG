#pragma once

#include <iostream>

class Chara
{
public:
    virtual void attack(Chara& c);
    void stun(Chara& c) { c.stunned = true; }

    void end_turn();

    bool is_dead() const { return HP <= 0; }
    bool is_stunned() const { return stunned; }

    virtual void special_move(Chara& c) = 0;
    virtual void take_damage(int atk) = 0;

    // TODO virtual
    virtual void display_state() const;

    virtual std::string class_name() const = 0;

    // chance between 0 and 1.
    // 0.2 means 20% chance of success, etc..
    bool roll(float chance);

protected:
    int HP;
    int atk;
    int cooldown;

    int current_cooldown = 0;
    bool stunned = false;

};

