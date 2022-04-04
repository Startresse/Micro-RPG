#include "Game.h"

#include <iostream>
#include <algorithm>

void Game::run()
{
    Orc orc;
    Knight knight;

    int round = 0;

    while (!knight.is_dead() && !orc.is_dead())
    {
        std::cout << "turn " << ++round << std::endl;

        knight.special_move(orc);
        orc.special_move(knight);

        knight.attack(orc);
        orc.attack(knight);

        knight.display_state();
        orc.display_state();

        knight.end_turn();
        orc.end_turn();

        std::cout << std::endl;
    }

    if (orc.is_dead() && knight.is_dead())
        std::cout << "TIE" << std::endl;
    else if (!orc.is_dead())
        std::cout << "Orc wins" << std::endl;
    else
        std::cout << "Knight wins" << std::endl;
}
//void Game::run()
//{
//    roll_initiative();
//
//    while (!is_finished())
//    {
//        turn();
//        display_state();
//    }
//
//}
//
//void Game::turn()
//{
//    for (auto i : playing_order)
//    {
//        Chara& current_player = players[i];
//
//        // TODO stun check
//        current_player.attack(players[(i + 1) % players.size()]);
//        // TODO implement the rest
//    }
//}
//
//// TODO update this with multiple players
//bool Game::is_finished()
//{
//    for (const auto& c : players)
//    {
//        if (c.is_dead())
//            return true;
//    }
//
//    return false;
//}
//
//void Game::display_state()
//{
//    for (const auto& c : players)
//        c.display_state();
//}
//
//void Game::roll_initiative()
//{
//    // prepare vector to avoid vector reallocation
//    playing_order.reserve(players.size());
//
//    // fill vector with player IDs (from 0 to n-1).
//    for (unsigned int i = 0; i < players.size(); ++i)
//        playing_order.push_back(i);
//
//    std::random_shuffle(playing_order.begin(), playing_order.end());
//
//    // display
//    for (unsigned int i = 0; i < playing_order.size(); ++i)
//        std::cout << playing_order[i] << " > ";
//    std::cout << playing_order.back() << std::endl;
//
//}
