#pragma once

#include <iosfwd>
#include <vector>

class Chara;
enum class classes;

class Team
{
public:
    Team() : characters(std::vector<Chara*>(0)) {}
    ~Team();

    void add_player(classes c);
    void retarget();
    void set_enemy_team(Team* team);

    bool lost() const;
    void display_state() const;
    void special_move();
    void attack();
    void end_turn() const;

    Chara* get_first_alive_chara() const;
    Chara* get_random_alive_chara() const;
    Chara* get_most_damaged_chara() const;
    int size() const { return static_cast<int>(characters.size()); }

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

private:
    std::vector<Chara*> characters;

    Team* enemy_team = nullptr;
};

