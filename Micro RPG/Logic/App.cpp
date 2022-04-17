#include "App.h"

#include <iostream>

#include "Misc/Utility.h"
#include "Settings.h"
#include "GameSettings.h"
#include "Game.h"

App::App() : gs(new GameSettings()) {}

App::~App() { delete gs; }

int App::run()
{
    display_header();

    while (true)
    {
        display_menu();

        switch (Utility::int_input())
        {
        case QUIT:
            return 0;
        case START_GAME:
        {
            nb_games++;

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

void App::display_header()
{
    std::cout << "---WELCOME TO MICRO RPG!---\n";
}

void App::display_menu()
{
    std::cout << "\nGame Menu\n";

    if (nb_games == 0)
        std::cout << START_GAME << " : Play a game.\n";
    else
        std::cout << START_GAME << " : Play another game.\n";

    std::cout << SETTINGS << " : Settings.\n";
    std::cout << QUIT << " : Exit program.\n";
}

