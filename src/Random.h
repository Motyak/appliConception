#ifndef RANDOM_H
#define RANDOM_H

#include "Ai.h"
#include "Model.h"

#include <random>

class Random : public Ai
{
    std::random_device rand;

  public:
    unsigned nextMove(Model::Board board);
};

#endif