#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Ihm.h"
#include "Model.h"
#include "Random.h"

#include <memory>

class Ihm;

class Controller
{
    std::unique_ptr<Ihm> ihm;
    std::unique_ptr<Model> model;
    std::unique_ptr<Ai> ai;

    void playMove(unsigned from, unsigned to);
    void aiPlays();
  
  public:
    Controller(Ihm* ihm);
    void updateView();
    bool submitMove(unsigned from, unsigned to);
    void incrementTurn();
};

#endif