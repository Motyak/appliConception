#include "Controller.h"

Controller::Controller(Ihm* ihm, Model* model)
{
    this->ihm = std::unique_ptr<Ihm>(ihm);
    this->model = std::unique_ptr<Model>(model);
}