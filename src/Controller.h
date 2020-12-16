#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Ihm.h"
#include "Model.h"
#include "Random.h"

#include <memory>

class Ihm;

/**
 * @brief Is responsible for executing the app use cases and updating the view
 * 
 */
class Controller
{
    std::unique_ptr<Ihm> ihm;
    std::unique_ptr<Model> model;
    std::unique_ptr<Ai> ai;

    void playMove(unsigned from, unsigned to);
    void aiPlays();
    bool checkOnWin();
  
  public:
    Controller(Ihm* ihm);
    void updateView();
    bool submitMove(unsigned from, unsigned to);
    void renewGame();
    void incrementTurn();
};

#endif