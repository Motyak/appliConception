#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>

class Model
{
  public:
    enum class Tile { EMPTY, X, O };
    enum class Player { X, O };
    class Board
    {
        unsigned dim;
        std::vector<std::shared_ptr<Tile>> tiles;

      public:
        Board(unsigned dim);

        const unsigned& getDim()const;
        Tile& operator[](unsigned i);

        std::string calculateOutcome()const;
        void clear();
        void print()const;
    };

  private:
    Player turn;
    Board grid;

  public:
    const Player& getTurn()const;
    Board& getGrid();
    void setTurn(const Player turn);
    void setGrid(const Board board);


};
#endif