#include "IhmSfml.h"
#include "IhmCli.h"

#include <memory>

int main()
{
     Ihm* game = new IhmSfml();
    // Ihm* game = new IhmCli();

    game->run();

    return 0;
}
