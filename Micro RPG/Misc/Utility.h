#pragma once

#include <random>

// TODO split ?
class Utility
{
public:
    // random number generation
    static bool roll(float success_rate);
    static auto random_value();
    static int random_value(int min, int max);

    static auto& generator() { return engine; }

    // for getting player input consistency
    static char int_input();

    // for float equality consistency
    static constexpr float epsilon = 0.0001f;

private:
    static std::mt19937 engine;
};

