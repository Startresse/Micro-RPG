#include "Team.h"

#include <iostream>
#include <numeric>

#include "Charas/Classes.h"
#include "Charas/Dummy.h"
#include "Charas/Knight.h"
#include "Charas/Orc.h"
#include "Charas/WhiteMage.h"
#include "Misc/Utility.h"

Team::~Team()
{
    for (auto c : characters)
        delete c;
}

void Team::add_player(classes c)
{
    switch (c)
    {
    case classes::Dummy:
        characters.push_back(new Dummy(5));
        break;
    case classes::Knight:
        characters.push_back(new Knight());
        break;
    case classes::Orc:
        characters.push_back(new Orc());
        break;
    case classes::WhiteMage:
        characters.push_back(new WhiteMage());
    default:
        break;
    }
}

void Team::set_enemy_team(Team* team)
{
    enemy_team = team;
    retarget();
}

// a team looses when all of its member are dead
bool Team::lost() const
{
    for (const Chara* chara : characters)
    {
        if (!chara->is_dead())
            return false;
    }

    return true;
}

void Team::display_state() const
{
    for (const Chara* chara : characters)
        chara->display_state();
}

// TODO beter targeting system
Chara* Team::get_first_alive_chara() const
{
    for (Chara* chara : characters)
    {
        if (!chara->is_dead())
            return chara;
    }

    return nullptr;
}

// TODO test
Chara* Team::get_random_alive_chara() const
{
    std::vector<int> char_id(size());
    std::iota(char_id.begin(), char_id.end(), 0);
    std::shuffle(char_id.begin(), char_id.end(), Utility::generator());

    for (int i : char_id)
    {
        Chara* chara = characters[i];
        if (!chara->is_dead())
            return chara;
    }

    return nullptr;
}

Chara* Team::get_most_damaged_chara() const
{
    Chara* tmp_most_damaged = characters[0];
    int max_lost_hp = tmp_most_damaged->lost_hp();

    for (std::vector<Chara*>::const_iterator it = std::next(characters.begin()); it != characters.end(); ++it)
    {
        if ((*it)->is_dead())
            continue;

        if ((*it)->lost_hp() > max_lost_hp)
        {
            tmp_most_damaged = *it;
            max_lost_hp = tmp_most_damaged->lost_hp();
        }
    }

    return tmp_most_damaged;
}

void Team::retarget()
{
    for (Chara* chara : characters)
    {
        if (!chara->is_dead())
            chara->reset_target(enemy_team, this);
    }
}

// TODO remove Team and and target to Chara
void Team::special_move()
{
    for (Chara* chara : characters)
    {
        if (chara->is_dead())
            continue;

        chara->reset_target(enemy_team, this);
        chara->special_move();
    }
}

void Team::attack()
{
    for (Chara* chara : characters)
    {
        if (chara->is_dead())
            continue;

        chara->reset_target(enemy_team, this);
        chara->attack();
    }
}

void Team::end_turn() const
{
    for (Chara* chara : characters)
    {
        if (chara->is_dead())
            continue;

        chara->end_turn();
    }
}

std::ostream& operator<<(std::ostream& os, const Team& team)
{
    int n = static_cast<int>(team.characters.size());

    for (int i = 0; i < n; ++i)
        os << team.characters[i]->name() << (i != n - 1 ? " | " : "");

    return os;
}
