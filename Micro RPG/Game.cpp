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
        std::cout << "\nTURN " << ++round << "\n\n";

        knight.display_state();
        orc.display_state();

        std::cout << "\nSPECIAL MOVES:\n";
        knight.special_move(orc);
        orc.special_move(knight);

        knight.display_state();
        orc.display_state();

        std::cout << "\nNORMAL MOVES:\n";
        knight.attack(orc);
        orc.attack(knight);

        knight.end_turn();
        orc.end_turn();

        knight.display_state();
        orc.display_state();

        std::cout << std::endl;
    }

    if (orc.is_dead() && knight.is_dead())
        std::cout << "TIE" << std::endl;
    else if (!orc.is_dead())
        std::cout << "Orc wins" << std::endl;
    else
        std::cout << "Knight wins" << std::endl;
    std::cout << "\n\n\n";

}
