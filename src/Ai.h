#ifndef AI_H
#define AI_H

#include "Model.h"

class Ai
{
  protected:
    bool isValid(Model::Move move, Model::Board board, Model::Player player);
    bool positionedOnEdge(unsigned index);
    bool areOpposite(unsigned from, unsigned to);

  public:
    virtual Model::Move nextMove(Model::Board board, Model::Player player) = 0;
    virtual ~Ai() = default;
};

#endif