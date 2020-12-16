#ifndef MINMAX_H
#define MINMAX_H

#include "Ai.h"

#include <vector>
#include <utility>
#include <cmath>

using Eval = int;

class MinMax : public Ai
{
    std::vector<Model::Board> boards;
    std::vector<Model::Move> moves;
    std::pair<Model::Board*,Eval> bestOutcome;

    void genPossibleMoves(const Model::Board& board, const Model::Player& player);
    std::vector<Model::Board> genChildren(Model::Board& board);
    int evalFuncRec(Model::Board* node, unsigned depth);
    int evalFunc(Model::Board& board);
    Model::Move getAssociatedMove(Model::Board* board);

  public:
    Model::Move nextMove(Model::Board board, Model::Player player);
};

#endif