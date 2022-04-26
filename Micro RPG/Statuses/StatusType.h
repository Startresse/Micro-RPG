#include <vector>
#include <typeindex>
#include <map>

namespace statustype
{
    static std::vector<std::type_index> status_type_list;

    struct type_index
    {
        std::type_index index = std::type_index(typeid(void));
        int rank = 0;

        type_index() = default;
        type_index(std::type_index i) : index(i)
        {
            auto it = ranks.find(i);
            if (it != ranks.end())
                rank = it->second;
        }
        type_index(const std::type_info& i) : type_index(std::type_index(i)) {}

        static const std::map<std::type_index, int> ranks;

        bool operator<(const type_index& other) const
        {
            return rank < other.rank;
        }
    };

}

