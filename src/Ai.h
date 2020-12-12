#ifndef AI_H
#define AI_H

#include "Model.h"

class Ai
{
  public:
    virtual Model::Move nextMove(Model::Board board) = 0;
};

#endif