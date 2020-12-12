#include "Random.h"

unsigned Random::nextMove(Model::Board board)
{
    return this->rand() % Model::Board::SIZE;
}