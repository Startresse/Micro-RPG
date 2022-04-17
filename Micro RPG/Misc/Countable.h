#pragma once

#include <set>

template<typename t>
class Countable
{
protected:
    Countable()
    {
        int id = 0;
        while (taken_values.contains(++id)) {}

        taken_values.insert(id);
        ID = id;
    };
    ~Countable() { taken_values.erase(ID); }

    int ID;

    static std::set<int> taken_values;
};

template <typename t>
std::set<int> Countable<t>::taken_values = std::set<int>();
