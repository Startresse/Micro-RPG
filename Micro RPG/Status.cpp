#include "Status.h"

void Status::end_turn()
{
    remaining_duration--;
}

bool Status::is_active() const
{
    return remaining_duration > 0;
}
