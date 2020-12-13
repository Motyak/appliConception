#ifndef IHM_H
#define IHM_H

#include "Controller.h"
#include "Model.h"

#include <memory>

class Controller;

class Ihm
{
  protected:
    std::unique_ptr<Controller> ctrl;

  public:
    Ihm();
    virtual ~Ihm() = default;
    virtual void run() = 0;
    virtual void setView(Model::Board& board) = 0;
    virtual void setView(const Model::Player& turn) = 0;
    virtual void display() = 0;
    virtual void announceWinner(const Model::Player& winner) = 0;
};

#endif