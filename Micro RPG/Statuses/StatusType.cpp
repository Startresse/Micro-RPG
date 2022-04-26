#include "StatusType.h"

#include "Cooldown.h"
#include "DamageModifier.h"
#include "Shield.h"
#include "Stun.h"

using namespace statustype;

const std::map<std::type_index, int> type_index::ranks = []()
{
    std::map<std::type_index, int> result;
    std::type_index index_order[] =
    {
        std::type_index(typeid(Shield)),
        std::type_index(typeid(Cooldown)),
        std::type_index(typeid(Stun)),
        std::type_index(typeid(DamageModifier)),
    };

    for (size_t i = 0; i < std::size(index_order); ++i)
        result[index_order[i]] = static_cast<int>(i + 1);

    return result;
}();
