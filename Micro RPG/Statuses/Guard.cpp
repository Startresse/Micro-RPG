#include "Guard.h"

#include "Charas/Chara.h"

std::string Guard::status_value() const
{
    return guardian->name();
}
