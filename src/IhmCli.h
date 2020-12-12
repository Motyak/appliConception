#ifndef IHMCLI_H
#define IHMCLI_H

#include "Ihm.h"
#include "Model.h"

class IhmCli : public Ihm
{
    std::unique_ptr<Model> model;

  public:
    IhmCli();
    void run();
    void setView(const Model& model);
    void display();
};

#endif