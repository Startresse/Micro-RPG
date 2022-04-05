#pragma once

#include "Chara.h"

class Orc : public Chara
{
public:
    Orc();

    void special_move(Chara& c);

    std::string class_name() const { return "Orc"; }
};

