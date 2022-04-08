#pragma once

struct GameSettings;

class App
{
public:
    App();
    ~App();

    int run();

protected:
    GameSettings* gs;
    int nb_games = 0;

    void display_menu();
    void display_header();


    enum InputHandler
    {
        START_GAME = 1,
        SETTINGS = 2,
        QUIT,
    };
};

