#include "Game.h"

#include <iostream>

#include "GameSettings.h"
#include "Classes.h"

Game::Game()
{
    team1.add_player(classes::Knight);
    team2.add_player(classes::Orc);

    team1.choose_target(team2);
    team2.choose_target(team1);

    std::cout << "\n\n\n\n---NEW GAME---\n\n\n\n";
    std::cout << "TEAM 1: " << team1 << std::endl;
    std::cout << "TEAM 2: " << team2 << std::endl;
    std::cout << std::endl;
}

void Game::run(const GameSettings& gs)
{
    int round = 0;
    while (!has_ended())
    {
        if (!gs.auto_turn)
        {
            std::cout << "press any key to continue...";
            (void)getchar();
        }

        std::cout << "\nTURN: " << ++round << "\n";
        turn();
    }

    game_end();

}

bool Game::has_ended()
{
    return team1.is_dead() || team2.is_dead();
}

void Game::turn()
{
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
    if (team1.is_dead() && team2.is_dead())
        std::cout << "TIE" << std::endl;
    else if (team1.is_dead())
        std::cout << "TEAM 2: " << team2 << " wins" << std::endl;
    else
        std::cout << "TEAM 1: " << team1 << " wins" << std::endl;
    std::cout << "\n\n\n";
}

void Game::display_state()
{
    std::cout << "Team 1: ";
    team1.display_state();
    std::cout << "Team 2: ";
    team2.display_state();
}

void Game::special_moves()
{
    team1.special_move();
    team2.special_move();
}

void Game::normal_attacks()
{
    team1.attack();
    team2.attack();
}

void Game::end_turn()
{
    team1.end_turn();
    team2.end_turn();
}
