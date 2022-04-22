#include "Status.h"

void Status::end_turn()
{
    if (remaining_duration == -1)
        return;

    remaining_duration = std::max(remaining_duration - 1, 0);
}

bool Status::is_active() const
{
    return remaining_duration > 0 || remaining_duration == -1;
}
