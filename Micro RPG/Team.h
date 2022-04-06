#pragma once

#include "Chara.h"

enum class classes;

class Team
{
public:
    Team() : chara(nullptr) {}
    ~Team() { delete chara; }

    void add_player(classes c);
    void choose_target(Team& t);

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    bool is_dead();
    void display_state();
    void special_move(Team& t);
    void attack(Team& t);
    void end_turn();

    Chara* get_chara() { return chara; }

private:
    Chara* chara;
};

