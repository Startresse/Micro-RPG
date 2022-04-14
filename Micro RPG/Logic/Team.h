#pragma once

#include <iostream>
#include <vector>

class Chara;
enum class classes;

enum class TargetSystem
{
    FOCUS,
    RANDOM,
};

class Team
{
public:
    Team() : characters(std::vector<Chara*>(0)), target_system(TargetSystem::RANDOM) {}
    ~Team();

    void add_player(classes c);
    void target();
    void set_enemy_team(Team* team);

    void check_update_target(Chara* chara);

    bool lost();
    void display_state();
    void special_move();
    void attack();
    void end_turn();

    Chara* get_first_alive_chara();
    Chara* get_random_alive_chara();
    int size() { return static_cast<int>(characters.size()); }

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

private:
    std::vector<Chara*> characters;
    TargetSystem target_system;

    Team* enemy_team = nullptr;

    Chara* get_target();
};

