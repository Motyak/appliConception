#include "Model.h"

#include <iostream>

Model::Board::Board(unsigned dim) : dim(dim)
{
    int size = dim * dim;
    for(int i = 0 ; i < size ; ++i)
        this->tiles.push_back(std::make_shared<Model::Tile>(Model::Tile::EMPTY));
}

const unsigned& Model::Board::getDim()const
{
    return this->dim;
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
    for(int row = 0 ; row < this->dim ; ++row)
    {
        for(int col = 0 ; col < this->dim ; ++col)
            std::cout<<map[(int)*this->tiles.at(row * this->dim + col).get()]<<"\t";
        std::cout<<std::endl;
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