#include "Controller.h"

Controller::Controller(Ihm* ihm)
{
    this->ihm = std::unique_ptr<Ihm>(ihm);
    this->model = std::make_unique<Model>();
    this->ai = std::make_unique<Random>();
}

void Controller::updateView()
{
    this->ihm->setView(this->model->getGrid());
    this->ihm->setView(this->model->getTurn());
}

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

void Controller::renewGame()
{
    this->model->clearBoard();
    this->updateView();
}

void Controller::incrementTurn()
{
    this->model->incrementTurn();
    this->updateView();
}

void Controller::playMove(unsigned from, unsigned to)
{
    this->model->playMove(from, to);
    this->updateView();
}

void Controller::aiPlays()
{
    Model::Board& grid = this->model->getGrid();
    Model::Player& turn = this->model->getTurn();
    
    Model::Move nextMove = this->ai->nextMove(grid, turn);
    this->playMove(nextMove.from, nextMove.to);
}

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
