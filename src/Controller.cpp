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
    if(this->model->submitMove(from, to))
        this->playMove(from, to);
}

void Controller::playMove(unsigned from, unsigned to)
{
    this->model->playMove(from, to);
    this->updateView();
}