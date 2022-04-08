#include <cstdlib>
#include <ctime>

#include "Logic/App.h"

int main()
{
    // Init randomness in program
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    App app;
    return app.run();
}
