#pragma once

#include <vector>
#include <random>

#include "Chara.h"

//TODO remove ?
#include "Orc.h"
#include "Knight.h"

class Game
{
public:
    Game() { std::srand(static_cast<unsigned int>(std::time(nullptr))); }

    void run();

};

