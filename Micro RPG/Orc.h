#pragma once

#include "Chara.h"

class Orc : public Chara
{
public:
    Orc() : Chara(60, 8, 5) {}

    void special_move();

    std::string class_name() const { return "Orc"; }
};

