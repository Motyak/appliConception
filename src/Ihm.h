#ifndef IHM_H
#define IHM_H

// #include "Controller.h"

class Ihm
{
  public:
    // virtual Ihm(Controller* ctrl) = 0;
    virtual void run() = 0;
    virtual void display() = 0;
};

#endif