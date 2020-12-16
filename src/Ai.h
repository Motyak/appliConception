#ifndef AI_H
#define AI_H

#include "Model.h"

#include <memory>

class Ai
{
  protected:
    std::unique_ptr<Model> model;

  public:
    virtual Model::Move nextMove(Model::Board board, Model::Player player) = 0;
    
    Ai();
    virtual ~Ai() = default;
};

#endif