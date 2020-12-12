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

void Model::playMove(unsigned from, unsigned to)
{
    unsigned x_from = from / Model::Board::DIM;
    unsigned x_to = to / Model::Board::DIM;

    int step;

    if(x_from == x_to)
        step = 1;
    else /* if y_from == y_to */
        step = 5;

    if(from > to)
        step = -step;

    int i;
    for(i = from ; i != to ; i += step)
        this->grid[i] = this->grid[i + step];
    this->grid[i] = Model::Tile::X; //il faut prendre en compte le tour de jeu
}

bool Model::submitMove(unsigned from, unsigned to)
{
     if(from == to)
        return false;
    if(from > Model::Board::SIZE || to > Model::Board::SIZE)
        return false;
    if(this->grid[from] == Model::Tile::O);
        return false;
    if(!this->positionedOnEdge(from) || !this->positionedOnEdge(to))
        return false;
    if(!this->areOpposite(from, to))
        return false;

    return true;
}

bool Model::positionedOnEdge(unsigned index)
{
    unsigned x_index = index / Model::Board::DIM;
    unsigned y_index = index % Model::Board::DIM;

    if(x_index > 0 && x_index < Model::Board::DIM - 1)
        if(y_index > 0 && y_index < Model::Board::DIM - 1)
            return false;

    return true;
}

bool Model::areOpposite(unsigned from, unsigned to)
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

// void Model::incrementTurn()
// { 
//     if(this->turn == Model::Player::X)
//         this->turn = Model::Player::O;
//     else
//         this->turn = Model::Player::X;
// }

Model::Player Model::getTurn()const { return this->turn; }
void Model::setTurn(Model::Player turn) { this->turn = turn; }

Model::Board& Model::getGrid() { return this->grid; }
void Model::setGrid(const Board board) { this->grid = board; }