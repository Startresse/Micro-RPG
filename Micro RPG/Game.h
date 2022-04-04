#pragma once

#include <vector>
#include <random>

#include "Chara.h"

//TODO remove ?
#include "Orc.h"

class Game
{
public:
    Game() { std::srand(static_cast<unsigned int>(std::time(nullptr))); }
    //Game() : players(0) { std::srand(static_cast<unsigned int>(std::time(nullptr))); }
//
//    //void add_player(const Chara& c) { players.push_back(c); }
    void run();
//
//private:
//    std::vector<Chara> players;
//    std::vector<int> playing_order;
//
//
//    void turn();
//
//    // determines the order of the players.
//    void roll_initiative();
//
//    void display_state();
//
//    bool is_finished();

};

