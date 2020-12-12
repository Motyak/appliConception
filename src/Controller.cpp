#include "Controller.h"

Controller::Controller(Ihm* ihm)
{
    this->ihm = std::unique_ptr<Ihm>(ihm);
    this->model = std::make_unique<Model>();
    this->ai = std::make_unique<Random>();
}

bool Controller::submitMove(unsigned from, unsigned to)
{
    // stub : false
}