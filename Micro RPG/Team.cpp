#include "Team.h"

void Team::add_player(classes c)
{
    switch (c)
    {
    case classes::Knight:
        chara = new Knight();
        break;
    case classes::Orc:
        chara = new Orc();
        break;
    default:
        break;
    }
}

bool Team::is_dead()
{
    return chara->is_dead();
}

void Team::display_state()
{
    chara->display_state();
}

// TODO remove Team and and target to Chara
void Team::special_move(Team& t)
{
    chara->special_move(t.target());
}

void Team::attack(Team& t)
{
    chara->attack(t.target());
}

void Team::end_turn()
{
    chara->end_turn();
}

std::ostream& operator<<(std::ostream& os, const Team& team)
{
    os << team.chara->class_name();
    return os;
}
