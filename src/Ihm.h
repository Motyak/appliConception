#ifndef IHM_H
#define IHM_H

#include "Controller.h"

#include <memory>

class Controller;

class Ihm
{
    std::unique_ptr<Controller> ctrl;

  public:
    Ihm();
    virtual void run() = 0;
    virtual void display() = 0;
};

#endif