#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Ihm.h"
#include "Model.h"

#include <memory>

class Controller
{
    std::unique_ptr<Ihm> ihm;
    std::unique_ptr<Model> model;
  
  public:
    Controller(Ihm* ihm, Model* model);
};
#endif