#include "Ai.h"

bool Ai::isValid(Model::Move move, Model::Board board, Model::Player player)
{
    if(move.from == move.to)
        return false;
    if(move.from > Model::Board::SIZE || move.to > Model::Board::SIZE)
        return false;
    if(board[move.from] == Model::getOpponentTile(player))
        return false;
    if(!this->positionedOnEdge(move.from) || !this->positionedOnEdge(move.to))
        return false;
    if(!this->areOpposite(move.from, move.to))
        return false;

    return true;
}

bool Ai::positionedOnEdge(unsigned index)
{
    unsigned x_index = index / Model::Board::DIM;
    unsigned y_index = index % Model::Board::DIM;

    if(x_index > 0 && x_index < Model::Board::DIM - 1)
        if(y_index > 0 && y_index < Model::Board::DIM - 1)
            return false;

    return true;
}

bool Ai::areOpposite(unsigned from, unsigned to)
{
    unsigned x_from = from / Model::Board::DIM;
    unsigned y_from = from % Model::Board::DIM;
    const unsigned opposites[] {
        0 + Model::Board::DIM * x_from,
        0 * Model::Board::DIM + y_from,
        4 + Model::Board::DIM * x_from,
        4 * Model::Board::DIM + y_from
    };
    for(int i : opposites)
        if(to == i)
            return true;
    return false;
}