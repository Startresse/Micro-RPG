#include "Game.h"

#include <iostream>
#include <conio.h>

#include "GameSettings.h"
#include "Charas/Classes.h"

Game::Game()
{
    std::cout << "\n\n\n\n---NEW GAME---\n\n\n\n";

    team1.add_player(classes::Knight);
    team1.add_player(classes::Knight);

    team2.add_player(classes::Orc);
    team2.add_player(classes::WhiteMage);

    std::cout << "TEAM 1: " << team1 << std::endl;
    std::cout << "TEAM 2: " << team2 << std::endl;
    std::cout << std::endl;

    team1.set_enemy_team(&team2);
    team2.set_enemy_team(&team1);

    std::cout << std::endl;
}

void Game::run(const GameSettings* gs)
{
    while (!has_ended())
    {
        if (!gs->auto_turn)
        {
            std::cout << "press any key to continue...";
            (void)_getch();
        }

        std::cout << "\n\n\n\n-----------------------\n\n\n\n";
        std::cout << "TURN: " << ++nb_round << "\n\n\n\n";
        turn();
    }

    game_end();

}

bool Game::has_ended()
{
    return team1.lost() || team2.lost();
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
    if (team1.lost() && team2.lost())
        std::cout << "TIE" << std::endl;
    else if (team1.lost())
        std::cout << "TEAM 2 " << team2 << " wins" << std::endl;
    else
        std::cout << "TEAM 1 " << team1 << " wins" << std::endl;
    std::cout << "\n\n\n";
}

void Game::display_state()
{
    std::cout << "Team 1:\n";
    team1.display_state();
    std::cout << "Team 2:\n";
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

void Game::retarget()
{
    team1.retarget();
    team2.retarget();
}
