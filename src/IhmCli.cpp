#include "IhmCli.h"

#include <iostream>
#include <regex>
#include <thread>
#include <chrono>

IhmCli::IhmCli()
{
    // has its own model
    this->model = std::make_unique<Model>();
}

// repl env
void IhmCli::run()
{
    std::string input = "";
    unsigned from, to;
    this->display();

    do
    {
        /* Read and Evaluate */
        std::cout<<"Quel sera votre prochain coup ?"<<std::endl;
        do
        {
            if(this->prompt(input) == "exit")
                return;
            this->getInputs(input, from, to);
        } while(!this->ctrl->submitMove(from, to));


        /* Print */
        this->display();


        /* Loop */
    } while(input != "exit");
}

void IhmCli::announceWinner(const Model::Player& winner)
{
    this->display();
    if(winner == Model::Player::X)
        std::cout<<"Joueur X a gagné!"<<std::endl;
    else /* Y */
        std::cout<<"Joueur Y a gagné!"<<std::endl;
    this->pause(2);
}

void IhmCli::setView(const Model::Board& board)
{
    this->model->setGrid(board);
}

void IhmCli::setView(const Model::Player& turn)
{
    this->model->setTurn(turn);
}

void IhmCli::display()
{
    this->clear();
    std::cout<<this->model->getGrid()<<std::endl;
}

void IhmCli::pause(unsigned s)
{
    std::this_thread::sleep_for(std::chrono::seconds(s));
}

void IhmCli::clear()
{
    std::cout<<"\e[2J";
}

void IhmCli::getInputs(const std::string& input, unsigned& from, unsigned& to)
{
    const std::regex expr("(\\d{1,2})\\,(\\d{1,2})");
    std::smatch matches;

    std::regex_search(input, matches, expr);
    from = std::stoul(matches[1].str());
    to = std::stoul(matches[2].str());
}

std::string IhmCli::prompt(std::string& input)
{
    std::cout<<"\u001b[32mquixo\u001b[0m> ";
    std::cin>>input;
    return input;
}
