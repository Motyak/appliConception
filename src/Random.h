#ifndef RANDOM_H
#define RANDOM_H

#include "Ai.h"
#include "Model.h"

#include <random>
#include <algorithm>
#include <array>

/**
 * @brief Is responsible for generating random moves
 * 
 */
class Random : public Ai
{
    std::random_device rand;

    Model::Move generateMove();

  public:
    Model::Move nextMove(Model::Board board, Model::Player player);
};

#endif