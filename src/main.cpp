#include "IhmSfml.h"
#include "IhmCli.h"

#include <memory>

int main()
{
    // Ihm* game = new IhmCli();
    Ihm* game = new IhmSfml();

    game->run();

    return 0;
}
