#include <iostream>

#include "Game.h"
#include "Orc.h"
#include "Knight.h"

int main()
{
    Game game;

    //game.add_player(Orc());
    //game.add_player(Orc());
    //game.add_player(Knight());

    std::cout << "Game starts!" << std::endl;

    game.run();

}
