#pragma once

class Utility
{
public:
    static bool roll(float success_rate);
    static char input();

    static constexpr float epsilon = 0.0001f;
};

