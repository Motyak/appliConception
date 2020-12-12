#include "Model.h"

Model::Board::Board()
{
    for(int i = 0 ; i < Model::Board::SIZE ; ++i)
        this->tiles.push_back(std::make_shared<Model::Tile>(Model::Tile::EMPTY));
}

Model::Tile& Model::Board::operator[](unsigned i)
{
    return *this->tiles.at(i).get();
}

std::string Model::calculateOutcome()const
{
    return "";
}

void Model::clearBoard()
{
    for(const auto& t : this->grid.tiles)
        *t.get() = Model::Tile::EMPTY;
}

std::ostream& operator<<(std::ostream& os, const Model::Board& board)
{
    const std::string map[] = {"\\", "X", "O"};
    for(int row = 0 ; row < Model::Board::DIM ; ++row)
    {
        for(int col = 0 ; col < Model::Board::DIM ; ++col)
            os<<map[(int)*board.tiles.at(row * Model::Board::DIM + col).get()]<<"\t";
        os<<"\n\n\n";
    }
    return os;
}

const Model::Player& Model::getTurn()const
{
    return this->turn;
}

Model::Board& Model::getGrid()
{
    return this->grid;
}

void Model::setTurn(const Player turn)
{
    this->turn = turn;
}

void Model::setGrid(const Board board)
{
    this->grid = board;
}