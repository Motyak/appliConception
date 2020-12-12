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

Model::Player* Model::calculateOutcome()
{
    // calculer l'outcome
    // si y'a gagnant, on retourne l'adresse du joueur courant
    // sinon on return nullptr

    return nullptr;
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
    this->grid[i] = Model::getTile(this->getTurn());
}

bool Model::submitMove(unsigned from, unsigned to)
{
     if(from == to)
        return false;
    if(from > Model::Board::SIZE || to > Model::Board::SIZE)
        return false;
    if(this->grid[from] == Model::getOpponentTile(this->getTurn()))
        return false;
    if(!this->positionedOnEdge(from) || !this->positionedOnEdge(to))
        return false;
    if(!this->areOpposite(from, to))
        return false;

    return true;
}

void Model::incrementTurn()
{
    if(this->turn == Model::Player::X)
        this->turn = Model::Player::O;
    else
        this->turn = Model::Player::X;
}

Model::Tile Model::getTile(Model::Player p)
{
    if(p == Model::Player::X)
        return Model::Tile::X;
    else
        return Model::Tile::O;
}

Model::Tile Model::getOpponentTile(Model::Player p)
{
    if(p == Model::Player::X)
        return Model::Tile::O;
    else
        return Model::Tile::X;
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

Model::Player& Model::getTurn() { return this->turn; }
void Model::setTurn(Model::Player turn) { this->turn = turn; }

Model::Board& Model::getGrid() { return this->grid; }
void Model::setGrid(const Board& board) { this->grid = board; }
