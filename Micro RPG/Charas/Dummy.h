#pragma once

#include "CountableChara.h"

class Dummy : public CountableChara<Dummy>
{
public:
    Dummy(int HP_) : CountableChara(HP_, 0, 0, 0) {}

    std::string class_name() const { return "Dummy"; }
    std::string special_move_name() const { return "NONE"; }

protected:
    void skill() {};

};