#include "IhmSfml.h"

#include <memory>

int main()
{
    Ihm* game = new IhmSfml();
    game->run();

    return 0;
}