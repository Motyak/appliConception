#ifndef IHM_H
#define IHM_H

#include "Controller.h"
#include "Model.h"

#include <memory>

class Controller;

/**
 * @brief Is responsible for displaying the views and handling user events
 * 
 */
class Ihm
{
  protected:
    std::unique_ptr<Controller> ctrl;

  public:
    Ihm();
    virtual ~Ihm() = default;
    /**
     * @brief Run the user interface
     * 
     */
    virtual void run() = 0;
    /**
     * @brief Set the view based on the model board
     * 
     * @param board The board to set to the view
     */
    virtual void setView(Model::Board& board) = 0;
    /**
     * @brief Set the view based on the model turn
     * 
     * @param turn The player whose turn it is to play
     */
    virtual void setView(const Model::Player& turn) = 0;
    /**
     * @brief Display the views
     * 
     */
    virtual void display() = 0;
    /**
     * @brief Announce who the winner of the game is
     * 
     * @param winner The winner of the game
     */
    virtual void announceWinner(const Model::Player& winner) = 0;
};

#endif