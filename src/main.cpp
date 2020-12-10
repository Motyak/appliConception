#include "Ihm.h"
#include "IhmSfml.h"

int main()
{
    Ihm* game = new IhmSfml();
    game->run();

    return 0;
}