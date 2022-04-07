#include "Team.h"

#include "Classes.h"
#include "Knight.h"
#include "Orc.h"

Team::~Team()
{
    delete chara;
}

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

void Team::choose_target(Team& team)
{
    chara->set_target(team.get_chara());
}

// TODO remove Team and and target to Chara
void Team::special_move()
{
    if (chara->is_on_CD())
        std::cout << chara->class_name() << " special move is on CD.\n";
    else
        chara->special_move();
}

void Team::attack()
{
    chara->attack();
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
