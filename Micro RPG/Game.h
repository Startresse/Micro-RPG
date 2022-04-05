#pragma once

#include <vector>
#include <random>

#include "Chara.h"
#include "Team.h"

class Game
{
public:
    Game() { std::srand(static_cast<unsigned int>(std::time(nullptr))); }

    void run();

    void display_state();
    void end_turn();
    void special_moves();
    void normal_attacks();

    void turn(int turn_nb);
    void game_end();

    bool has_ended();

private:
    Team team1;
    Team team2;
};

