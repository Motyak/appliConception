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
        this->playMove(from, to);
        this->incrementTurn();

        this->aiPlays();
        this->incrementTurn();

        return true;
    }
    return false;
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

void Controller::incrementTurn()
{
    this->model->incrementTurn();
    this->updateView();
}
