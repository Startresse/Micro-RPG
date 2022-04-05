#include <iostream>

#include "Game.h"
#include "Orc.h"
#include "Knight.h"

enum InputHandler
{
    START_GAME = 1,
};

int main()
{
    while(true)
    {
        std::cout << "---WELCOME TO MICRO RPG!---\n";
        std::cout << "Please provide an input:\n\n";
        std::cout << "1 : Play a game.\n";
        std::cout << "\nAny other input will end the program.\n";

        std::cout << "> ";
        int n;
        std::cin >> n;


        switch (n)
        {
        case START_GAME:
        {
            Game game;
            game.run();
            break;
        }
        default:
            return 0;
        }
    }

}
