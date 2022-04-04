#pragma once

#include "Chara.h"

class Orc : public Chara
{
public:
    Orc();

    void special_move(Chara& c);
    void take_damage(int atk);

    std::string class_name() const { return "Orc"; }
};

