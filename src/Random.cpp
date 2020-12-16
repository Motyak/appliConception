#include "Random.h"

/**
 * @brief Generate a random move based on the grid content and player turn
 * 
 * @param board grid content
 * @param player player turn
 * @return Model::Move a valid move
 */
Model::Move Random::nextMove(Model::Board board, Model::Player player)
{
    this->model->setGrid(board);
    this->model->setTurn(player);

    Model::Move move;
    do { move = this->generateMove(); } 
    while(!this->model->validMove(move.from, move.to));
    return move;
}

/**
 * @brief Generate a random move
 * 
 * @return Model::Move a move
 */
Model::Move Random::generateMove()
{
    unsigned x_from, y_from;

    x_from = this->rand() % Model::Board::DIM;
    if(x_from == 0 || x_from == 4)
        y_from = this->rand() % Model::Board::DIM;
    else /* si au milieu */
        y_from = (this->rand() % 2) * 4;

    std::vector<Model::Coord> opposites;
    if(x_from != 0)
        opposites.push_back({0, y_from});
    if(x_from != 4)
        opposites.push_back({4, y_from});
    if(y_from != 0)
        opposites.push_back({x_from, 0});
    if(y_from != 4)
        opposites.push_back({x_from, 4});
  
    Model::Coord opposite = opposites[this->rand() % opposites.size()];

    Model::Move nextMove = {
        x_from * Model::Board::DIM + y_from, 
        opposite.x * Model::Board::DIM + opposite.y
    };

    return nextMove;
}