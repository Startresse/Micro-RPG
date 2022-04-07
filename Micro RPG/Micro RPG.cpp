#include <iostream>

#include "Game.h"
#include "GameSettings.h"

enum InputHandler
{
    QUIT = 0,
    START_GAME = 1,
    SETTINGS = 2,
};

void settings(GameSettings& gs);

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
            settings(gs);
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }

}

enum InputHandlerSettings
{
    EXIT = 0,
    TOGGLE_AUTO_TURN = 1,
};

void settings(GameSettings& gs)
{
    while (true)
    {
        std::cout << "\nSettings menu\n";
        std::cout << TOGGLE_AUTO_TURN << " : toggle auto turn";
        std::cout << " (current: " << ((gs.auto_turn) ? "enabled" : "disabled") << ")";
        std::cout << " (default: " << ((gs.default_auto_turn) ? "enabled" : "disabled") << ")";
        std::cout << ".\n";
        std::cout << EXIT << " : Exit settings.\n";

        std::cout << "\n> ";
        char n;
        std::cin >> n;

        switch (n - static_cast<int>('0'))
        {
        case TOGGLE_AUTO_TURN:
            gs.auto_turn = !gs.auto_turn;
            std::cout << "Auto turn : " << ((gs.auto_turn) ? "enabled" : "disabled") << std::endl;
            break;
        case EXIT:
            std::cout << "Exit Settings...\n";
            return;
        default:
            std::cout << "Invalid input\n";
            break;
        }

    }

}
