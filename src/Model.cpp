#include "Model.h"

#include <map>

Model::Model()
{
    this->turn = Model::Player::X;
}

Model::Board::Board()
{
    for(int i = 0 ; i < Model::Board::SIZE ; ++i)
        this->tiles.push_back(std::make_shared<Model::Tile>(Model::Tile::EMPTY));
}

Model::Tile& Model::Board::operator[](unsigned i)
{
    return *this->tiles.at(i).get();
}

bool Model::hasAWinner()
{
    int sumRow, sumCol, sumDiag;
    sumRow = sumCol = sumDiag = 0;

    for(int x = 0 ; x < Model::Board::DIM ; ++x)
    {
        for(int y = 0 ; y < Model::Board::DIM ; ++y)
        {
            sumRow += (int)this->grid[x * Model::Board::DIM + y];
            sumCol += (int)this->grid[y * Model::Board::DIM + x];
        }
        if(sumRow == 5 || sumRow == -5) return true;
        sumRow = 0;
        if(sumCol == 5 || sumCol == -5) return true;
        sumCol = 0;

        sumDiag += (int)this->grid[x * Model::Board::DIM + x];
    }
    if(sumDiag == 5 || sumDiag == -5) return true;

    return false;

    // if(this->calculateRows())
    //     return true;
    // if(this->calculateCols())
    //     return true;
    // if(this->calculateDiags())
    //     return true;
    
    // return false;
}

bool Model::calculateRows()
{
    int sum = 0;
    int y = 0;
    for(int x = 0 ; x < Model::Board::DIM ; ++x)
        sum += (int)this->grid[x * Model::Board::DIM + y];

    std::cout<<"sumrows="<<sum<<std::endl;

    if(sum == 5 || sum == -5)
        return true;
    return false;
}

bool Model::calculateCols()
{
    int sum = 0;
    int x = 0;
    for(int y = 0 ; y < Model::Board::DIM ; ++y)
        sum += (int)this->grid[x * Model::Board::DIM + y];

    std::cout<<"sumcols="<<sum<<std::endl;

    if(sum == 5 || sum == -5)
        return true;
    return false;
}
    
bool Model::calculateDiags()
{
    /* à faire */
    return false;
}

void Model::clearBoard()
{
    for(const auto& t : this->grid.tiles)
        *t.get() = Model::Tile::EMPTY;
}

std::ostream& operator<<(std::ostream& os, const Model::Board& board)
{
    std::map<Model::Tile,std::string> map {
        {Model::Tile::EMPTY, "\\"},
        {Model::Tile::X, "X"},
        {Model::Tile::O, "O"}
    };
    for(int row = 0 ; row < Model::Board::DIM ; ++row)
    {
        for(int col = 0 ; col < Model::Board::DIM ; ++col)
            os<<map[*board.tiles.at(row * Model::Board::DIM + col).get()]<<"\t";
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
