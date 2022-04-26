#include "StatusType.h"

#include "Cooldown.h"
#include "DamageMultiplier.h"
#include "Shield.h"
#include "Stun.h"
#include "DamageFlat.h"

using namespace statustype;


const std::map<std::type_index, int> type_index::ranks = []()
{
    std::map<std::type_index, int> result;

    std::vector<std::type_index> status_type_list =
    {
        std::type_index(typeid(Shield)),
        std::type_index(typeid(Cooldown)),
        std::type_index(typeid(Stun)),
        std::type_index(typeid(DamageMultiplier)),
        std::type_index(typeid(DamageFlat)),
    };

    for (size_t i = 0; i < status_type_list.size(); ++i)
        result[status_type_list[i]] = static_cast<int>(i + 1);

    return result;
}();
