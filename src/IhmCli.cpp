#include "IhmCli.h"

#include <iostream>
#include <regex>

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
