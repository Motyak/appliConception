#ifndef AI_H
#define AI_H

#include "Model.h"

#include <memory>

/**
 * @brief Is responsible for generating moves
 * 
 */
class Ai
{
  protected:
    std::unique_ptr<Model> model;

  public:
  /**
   * @brief Generate a move based on the grid content and player turn
   * 
   * @param board the grid content
   * @param player the player turn
   * @return Model::Move a valid move
   */
    virtual Model::Move nextMove(Model::Board board, Model::Player player) = 0;
    
    Ai();
    virtual ~Ai() = default;
};

#endif