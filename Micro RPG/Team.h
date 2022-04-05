#pragma once

#include "Chara.h"
#include "Classes.h"

class Team
{
public:
    Team() : chara(nullptr) {}
    ~Team() { delete chara; }

    void add_player(classes c);

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    bool is_dead();
    void display_state();
    void special_move(Team& t);
    void attack(Team& t);
    void end_turn();

    // TODO remove
    Chara& target() { return *chara; }

private:
    Chara* chara;
};

