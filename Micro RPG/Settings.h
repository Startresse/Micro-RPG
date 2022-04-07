#pragma once

struct GameSettings;

class Settings
{
public:
    static void settings(GameSettings& gs);

private:
    enum InputHandlerSettings
    {
        EXIT = 0,
        TOGGLE_AUTO_TURN = 1,
    };

    
};

