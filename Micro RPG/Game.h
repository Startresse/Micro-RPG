#pragma once

#include <vector>

#include "Chara.h"

class Game
{
public:
    Game() : players(0) {}
    Game(const Game& game) : players(game.players) {}

    void add_player(const Chara& c) { players.push_back(c); }
    void run();

private:
    std::vector<Chara> players;
    std::vector<int> playing_order;


    void turn();

    // determines the order of the players.
    void roll_initiative();

    void display_state();

    bool is_finished();

};

