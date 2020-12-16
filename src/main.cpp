// #include "IhmSfml.h"
// #include "IhmCli.h"

#include "Model.h"
#include "MinMax.h"

int main()
{
    // // Ihm* game = new IhmCli();
    // Ihm* game = new IhmSfml();

    // game->run();


    Model model;
    MinMax ai;
    model.playMove(20,0); model.incrementTurn(); model.playMove(21,1);
    model.incrementTurn(); model.playMove(21,1); model.playMove(21,1);
    model.playMove(22,2); model.playMove(22,2); model.playMove(22,2);
    model.playMove(3,23); model.playMove(3,23);
    std::cout<<model.getGrid()<<std::endl;
    Model::Move nextMove = ai.nextMove(model.getGrid(), model.getTurn());

    return 0;
}
