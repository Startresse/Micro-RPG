#pragma once

class ShieldedUnit
{
protected:
    ShieldedUnit(int shield_value_) : shield_value(shield_value_) {}

    int shield_value;
    bool shield_just_broke = false;

    void take_hit(int &dmg);
    void end_turn();

    // Display
    void display_shield() const;
    void display_shield_broke() const;
};

