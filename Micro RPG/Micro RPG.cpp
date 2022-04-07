#include <iostream>

#include "Game.h"
#include "Settings.h"
#include "GameSettings.h"


enum InputHandler
{
    QUIT = 0,
    START_GAME = 1,
    SETTINGS = 2,
};

int main()
{
    GameSettings gs;

    std::cout << "---WELCOME TO MICRO RPG!---\n";
    std::cout << "\nPlease provide an input:\n";
    int nb_games = 0;
    while (true)
    {
        std::cout << "\nGame Menu\n";

        if (nb_games == 0)
            std::cout << START_GAME << " : Play a game.\n";
        else
            std::cout << START_GAME << " : Play another game.\n";

        std::cout << SETTINGS << " : Settings.\n";
        std::cout << QUIT << " : Exit program.\n";

        std::cout << "\n> ";
        char n;
        std::cin >> n;

        switch (n - static_cast<int>('0'))
        {
        case QUIT:
            return 0;
        case START_GAME:
        {

            // skips input so it doesn't override first Game input
            (void)getchar();

            nb_games++;

            std::cout << "\n\n\n\n---NEW GAME---\n\n\n\n";

            Game game;
            game.run(gs);

            break;
        }
        case SETTINGS:
            Settings::settings(gs);
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }

}

