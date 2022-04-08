#pragma once

#include <string>

#include "Chara.h"
#include "Countable.h"

template <typename t>
class CountableChara : public Chara, public Countable<t>
{
public:
    using Chara::Chara;

    std::string name() const
    {
        return class_name() + " " + std::to_string(this->ID);
    }

};
