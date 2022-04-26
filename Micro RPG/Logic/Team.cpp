#include "Team.h"

#include <iostream>
#include <numeric>

#include "Charas/Classes.h"
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
    target();
}

// a team looses when all of its member are dead
bool Team::lost()
{
    for (const Chara* chara : characters)
    {
        if (!chara->is_dead())
            return false;
    }

    return true;
}

void Team::display_state()
{
    for (const Chara* chara : characters)
        chara->display_state();
}

// TODO beter targeting system
Chara* Team::get_first_alive_chara()
{
    for (Chara* chara : characters)
    {
        if (!chara->is_dead())
            return chara;
    }

    return nullptr;
}

// TODO test
Chara* Team::get_random_alive_chara()
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

Chara* Team::get_target()
{
    Chara* target = nullptr;
    if (target_system == TargetSystem::FOCUS)
        target = enemy_team->get_first_alive_chara();
    else if (target_system == TargetSystem::RANDOM)
        target = enemy_team->get_random_alive_chara();

    return target;
}

void Team::target()
{
    for (Chara* chara : characters)
    {
        if (chara->has_good_target())
            continue;

        Chara* target = get_target();

        if (target == nullptr)
            return;

        chara->set_target(target);
    }
}

void Team::check_update_target(Chara* chara)
{
    if (!chara->has_good_target())
        chara->set_target(get_target());
}

// TODO remove Team and and target to Chara
void Team::special_move()
{
    for (Chara* chara : characters)
    {
        if (chara->is_dead())
            continue;

        check_update_target(chara);
        chara->special_move();
    }
}

void Team::attack()
{
    for (Chara* chara : characters)
    {
        if (chara->is_dead())
            continue;

        check_update_target(chara);
        chara->attack();
    }
}

void Team::end_turn()
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
