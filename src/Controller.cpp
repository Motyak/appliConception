#include "Controller.h"

#include <iostream>

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
    if(this->model->submitMove(from, to))
    {
        /* Player's turn */
        {
            this->playMove(from, to);
            this->incrementTurn();
            if(this->checkOnWin())
                return true;
        }

        /* AI's turn */
        {
            this->aiPlays();
            this->incrementTurn();
            this->checkOnWin();
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
    Model::Move nextMove;

    do { nextMove = this->ai->nextMove(this->model->getGrid()); }
    while(!this->model->submitMove(nextMove.from, nextMove.to));
    this->playMove(nextMove.from, nextMove.to);
}

bool Controller::checkOnWin()
{
    // récupérer l'outcome, si y'a un gagnant on
    // fait son annonce dans l'interface
    // puis on renew la game
}
