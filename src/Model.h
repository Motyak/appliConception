#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>
#include <iostream>

class Model
{
  public:
    enum class Player { X = 1, O = -1};
    // enum class Player { X , O };
    enum class Tile { EMPTY = 0, X = 1, O = -1 };
    struct Move { unsigned from, to; };
    struct Coord { unsigned x, y; };
    class Board
    {
        std::vector<std::shared_ptr<Tile>> tiles;

      public:
        static constexpr unsigned DIM = 5;
        static const unsigned SIZE = Board::DIM * Board::DIM;

        Board();
        Tile& operator[](unsigned i);
        friend std::ostream& operator<<(std::ostream& out, const Board& board);

        friend class Model;
    };

  private:
    Player turn;
    Board grid;

    bool positionedOnEdge(unsigned i);
    bool areOpposite(unsigned from, unsigned to);
    

  public:
    static Tile getTile(Player p);
    static Tile getOpponentTile(Player p);


    Model();
    Player& getTurn();
    Board& getGrid();
    void setTurn(const Player turn);
    void setGrid(const Board& board);

    bool validMove(unsigned from, unsigned to);
    bool hasAWinner();
    void clearBoard();
    void playMove(unsigned from, unsigned to);
    void incrementTurn();
};
#endif