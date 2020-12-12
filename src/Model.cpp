#include "Model.h"

#include <iostream>

Model::Board::Board()
{
    for(int i = 0 ; i < Model::Board::SIZE ; ++i)
        this->tiles.push_back(std::make_shared<Model::Tile>(Model::Tile::EMPTY));
}

Model::Tile& Model::Board::operator[](unsigned i)
{
    return *this->tiles.at(i).get();
}

std::string Model::Board::calculateOutcome()const
{
    return "";
}

void Model::Board::clear()
{
    for(const auto& t : this->tiles)
        *t.get() = Model::Tile::EMPTY;
}

void Model::Board::print()const
{
    const std::string map[] = {"\\", "X", "O"};
    for(int row = 0 ; row < Model::Board::DIM ; ++row)
    {
        for(int col = 0 ; col < Model::Board::DIM ; ++col)
            std::cout<<map[(int)*this->tiles.at(row * Model::Board::DIM + col).get()]<<"\t";
        std::cout<<"\n\n\n";
    }
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