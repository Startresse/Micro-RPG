#pragma once

#include "Team.h"

struct GameSettings;

class Game
{
public:
    Game();

    void run(const GameSettings* gs);

    void display_state();
    void end_turn();
    void special_moves();
    void normal_attacks();
    void retarget();

    void turn();
    void game_end();

    bool has_ended();

private:
    Team team1;
    Team team2;

    int nb_round = 0;
};

