#include <iostream>

#include "Game.h"

enum InputHandler
{
    QUIT = 0,
    START_GAME = 1,
};

int main()
{
    std::cout << "---WELCOME TO MICRO RPG!---\n";
    int nb_games = 0;
    while (true)
    {
        std::cout << "\nPlease provide an input:\n\n";

        if (nb_games == 0)
            std::cout << START_GAME << " : Play a game.\n";
        else
            std::cout << START_GAME << " : Play another game.\n";

        std::cout << QUIT << " : Exit program.\n";

        std::cout << "\n> ";
        char n;
        std::cin >> n;


        switch (n - static_cast<int>('0'))
        {
        case START_GAME:
        {
            nb_games++;

            Game game;
            game.run();

            break;
        }
        case QUIT:
            return 0;
        default:
            std::cout << "\nInvalid input\n";
            break;
        }
    }

}
