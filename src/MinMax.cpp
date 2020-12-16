#include "MinMax.h"

Model::Move MinMax::nextMove(Model::Board board, Model::Player player)
{
    // // generate the first depth of the tree
    // this->genPossibleMoves(board, player);

    // // evaluate each child recursively, starting at depth 0
    // for(auto& b : this->boards)
    //     this->evalFuncRec(&b, 0);

    // // return the best move found
    // return this->getAssociatedMove(this->bestOutcome.first);

    //debug
    std::cout<<this->evalFunc(board)<<std::endl;

    return {0,0};//stub
}

void MinMax::genPossibleMoves(const Model::Board& board, const Model::Player& player)
{
    this->model->setGrid(board);
    this->model->setTurn(player);
    for(unsigned from = 0 ; from < Model::Board::SIZE ; ++from)
        for(unsigned to = 0 ; to < Model::Board::SIZE ; ++to)
            if(this->model->validMove(from, to))
            {
                this->boards.push_back(board);
                this->moves.push_back({from, to});
            }
}

int MinMax::evalFuncRec(Model::Board* node, unsigned depth)
{
    // generate node children
    std::vector<Model::Board> children = this->genChildren(node);

    // if node is a leaf, evaluate its value
    if(children.empty())
    {
        int eval = this->evalFunc(*node);
        if(eval > this->bestOutcome.second)
        {
            this->bestOutcome.first = node;
            this->bestOutcome.second = eval;
        }
        return this->evalFunc(*node);
    }

    // maximizing
    if(depth == 0)
    {
        // -infinity
        int value = -9999;
        for(Model::Board& child : children)
            value = std::max(value, this->evalFuncRec(&child, 1));
        return value;
    }
    // minimizing
    else /* depth == 1 */
    {
        // +infinity
        int value = 9999;
        for(Model::Board& child : children)
            value = std::min(value, this->evalFuncRec(&child, 2));
        return value;
    }
}

std::vector<Model::Board> MinMax::genChildren(Model::Board* board)
{
    this->model->setGrid(*board);
    std::vector<Model::Board> children;

    for(int from = 0 ; from < Model::Board::SIZE ; ++from)
        for(int to = 0 ; to < Model::Board::SIZE ; ++to)
            if(this->model->validMove(from, to))
            {
                this->model->playMove(from, to);
                children.push_back(this->model->getGrid());
                this->model->setGrid(*board);
            }

    return children;
}

// Qui est le plus proche d'aligner 5 symboles?
int MinMax::evalFunc(Model::Board& board)
{
    int sumRow, sumCol, sumDiag1, sumDiag2, sumMax, sumMin;
    sumRow = sumCol = sumDiag1 = sumDiag2 = 0;
    sumMax = -9999;    sumMin = 9999;

    for(int x = 0 ; x < Model::Board::DIM ; ++x)
    {
        for(int y = 0 ; y < Model::Board::DIM ; ++y)
        {
            sumRow += (int)board[x * Model::Board::DIM + y];
            sumCol += (int)board[y * Model::Board::DIM + x];
        }
        if(sumRow > sumMax) sumMax = sumRow;
        if(sumRow < sumMin) sumMin = sumRow;
        if(sumCol > sumMax) sumMax = sumCol;
        if(sumCol < sumMin) sumMin = sumCol;
        sumRow = 0; sumCol = 0;

        sumDiag1 += (int)board[x * Model::Board::DIM + x];
        sumDiag2 += (int)board[x * Model::Board::DIM + (Model::Board::DIM - 1 - x)];
    }
    if(sumDiag1 > sumMax) sumMax = sumDiag1;
    if(sumDiag1 < sumMin) sumMin = sumDiag1;
    if(sumDiag2 > sumMax) sumMax = sumDiag2;
    if(sumDiag2 < sumMin) sumMin = sumDiag2;

    return sumMax + sumMin;
}

Model::Move MinMax::getAssociatedMove(Model::Board* board)
{
    for(int i = 0 ; i < this->boards.size() ; ++i)
        if(&this->boards[i] == board)
            return this->moves[i];
}