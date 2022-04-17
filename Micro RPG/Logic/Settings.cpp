#include "Settings.h"

#include <iostream>

#include "GameSettings.h"
#include "Misc/Utility.h"

void Settings::settings(GameSettings* gs)
{
    while (true)
    {
        std::cout << "\nSettings menu\n";
        std::cout << TOGGLE_AUTO_TURN << " : toggle auto turn";
        std::cout << " (current: " << ((gs->auto_turn) ? "enabled" : "disabled") << ")";
        std::cout << " (default: " << ((gs->default_auto_turn) ? "enabled" : "disabled") << ")";
        std::cout << ".\n";
        std::cout << EXIT << " : Exit settings.\n";

        switch (Utility::int_input())
        {
        case TOGGLE_AUTO_TURN:
            gs->auto_turn = !gs->auto_turn;
            std::cout << "Auto turn : " << ((gs->auto_turn) ? "enabled" : "disabled") << std::endl;
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
