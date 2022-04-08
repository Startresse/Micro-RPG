#pragma once

struct GameSettings;

class Settings
{
public:
    static void settings(GameSettings* gs);

private:
    enum InputHandlerSettings
    {
        TOGGLE_AUTO_TURN = 1,
        EXIT,
    };
};

