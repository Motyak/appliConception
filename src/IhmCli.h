#ifndef IHMCLI_H
#define IHMCLI_H

#include "Ihm.h"
#include "Model.h"

class IhmCli : public Ihm
{
    std::unique_ptr<Model> model;

    void clear();
    void getInputs(const std::string& input, unsigned& from, unsigned& to);
    std::string prompt(std::string& input);

  public:
    IhmCli();
    void run();
    void setView(const Model::Board& board);
    void setView(const Model::Player& turn);
    void announceWinner(Model::Player* winner);
    void display();
};

#endif