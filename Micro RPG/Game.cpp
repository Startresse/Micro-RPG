#include "Game.h"

#include <iostream>
#include <algorithm>

void Game::run()
{
    team1.add_player(classes::Knight);
    team2.add_player(classes::Orc);

    std::cout << "TEAM 1: " << team1 << std::endl;
    std::cout << "TEAM 2: " << team2 << std::endl;

    int round = 0;
    while (!has_ended())
    {
        turn(++round);
    }

    game_end();

}

bool Game::has_ended()
{
    return team1.is_dead() || team2.is_dead();
}

void Game::turn(int turn_nb)
{
    std::cout << "\nTURN: " << turn_nb << "\n";

    std::cout << "\nSPECIAL MOVES:\n";
    special_moves();
    display_state();

    std::cout << "\nNORMAL MOVES:\n";
    normal_attacks();
    display_state();

    std::cout << "\nEND TURN RESOLVE:\n";
    end_turn();
    display_state();

    std::cout << std::endl;
}

void Game::game_end()
{
    if (team1.is_dead())
        std::cout << "TEAM 2: " << team2 << " wins" << std::endl;
    else if (team2.is_dead())
        std::cout << "TEAM 1: " << team1 << " wins" << std::endl;
    else
        std::cout << "TIE" << std::endl;
    std::cout << "\n\n\n";
}

void Game::display_state()
{
    team1.display_state();
    team2.display_state();
}

void Game::special_moves()
{
    team1.special_move(team2);
    team2.special_move(team1);
}

void Game::normal_attacks()
{
    team1.attack(team2);
    team2.attack(team1);
}

void Game::end_turn()
{
    team1.end_turn();
    team2.end_turn();
}
