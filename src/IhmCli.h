#ifndef IHMCLI_H
#define IHMCLI_H

#include "Ihm.h"
#include "Model.h"

class IhmCli : public Ihm
{
    std::unique_ptr<Model> model;

    void clear();
    void getInputs(unsigned& from, unsigned& to);

  public:
    IhmCli();
    void run();
    void setView(const Model& model);
    void display();
};

#endif