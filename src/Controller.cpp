#include "Controller.h"

Controller::Controller(Ihm* ihm)
{
    this->ihm = std::unique_ptr<Ihm>(ihm);
    this->model = std::make_unique<Model>();
    this->ai = std::make_unique<Random>();
}

/**
 * @brief Updates the view content based on the model entities
 * 
 */
void Controller::updateView()
{
    this->ihm->setView(this->model->getGrid());
    this->ihm->setView(this->model->getTurn());
}

/**
 * @brief Submit a move to the model
 * 
 * @param from start index
 * @param to end index
 * @return true if the move is legal
 * @return false if the move is illegal
 */
bool Controller::submitMove(unsigned from, unsigned to)
{
    // if(this->model->submitMove(from, to))
    if(this->model->validMove(from, to))
    {
        /* Player's turn */
        {
            this->playMove(from, to);
            if(this->checkOnWin())
                return true;
            this->incrementTurn();
        }

        /* AI's turn */
        {
            this->aiPlays();
            this->checkOnWin();
            this->incrementTurn();
        }

        return true;
    }
    return false;
}

/**
 * @brief Clear the model grid and update the view
 * 
 */
void Controller::renewGame()
{
    this->model->clearBoard();
    this->updateView();
}

/**
 * @brief Gives turn to next player and update the view
 * 
 */
void Controller::incrementTurn()
{
    this->model->incrementTurn();
    this->updateView();
}

/**
 * @brief Play a move in the model grid and update the view
 * 
 * @param from start index
 * @param to end index
 */
void Controller::playMove(unsigned from, unsigned to)
{
    this->model->playMove(from, to);
    this->updateView();
}

/**
 * @brief Make the ai play a move in the model grid and update the view
 * 
 */
void Controller::aiPlays()
{
    Model::Board& grid = this->model->getGrid();
    Model::Player& turn = this->model->getTurn();
    
    Model::Move nextMove = this->ai->nextMove(grid, turn);
    this->playMove(nextMove.from, nextMove.to);
}

/**
 * @brief Check if the model has a winner, if so announce it and renew the game
 * 
 * @return true if there is a winner
 * @return false if not
 */
bool Controller::checkOnWin()
{
    if(this->model->hasAWinner())
    {
        this->ihm->announceWinner(this->model->getTurn());
        this->renewGame();
        return true;
    }
    return false;
}
