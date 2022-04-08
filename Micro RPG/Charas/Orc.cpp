#include "Orc.h"

const float Orc::default_skill_success_rate = 0.20f;

void Orc::skill()
{
    stun_target();
}

