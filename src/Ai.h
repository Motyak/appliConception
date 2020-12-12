#ifndef AI_H
#define AI_H

#include "Model.h"

class Ai
{
  public:
    virtual unsigned nextMove(Model::Board board) = 0;
};

#endif