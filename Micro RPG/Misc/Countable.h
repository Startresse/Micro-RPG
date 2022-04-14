#pragma once

template<typename t>
class Countable
{
protected:
    Countable() { ID = ++count; };

    static int count;

    int ID;
};

template<typename t>
int Countable<t>::count = 0;
