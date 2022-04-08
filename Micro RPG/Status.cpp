#include "Status.h"

void Status::end_turn()
{
    remaining_duration = std::max(remaining_duration - 1, 0);
}

bool Status::is_active() const
{
    return remaining_duration > 0;
}
