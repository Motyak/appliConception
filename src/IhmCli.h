#ifndef IHMCLI_H
#define IHMCLI_H

#include "Ihm.h"
#include "Model.h"

/**
 * @brief Is responsible for displaying the views and handling user events
 * 
 */
class IhmCli : public Ihm
{
    std::unique_ptr<Model> model;

    void clear();
    void pause(unsigned s);
    void getInputs(const std::string& input, unsigned& from, unsigned& to);
    std::string prompt(std::string& input);

  public:
    IhmCli();
    void run();
    void setView(Model::Board& board);
    void setView(const Model::Player& turn);
    void announceWinner(const Model::Player& winner);
    void display();
};

#endif