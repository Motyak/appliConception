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
    while(input != "exit")
    {
        /* Read */
        std::cout<<"Quel sera votre prochain coup ?"<<std::endl;
        this->getInputs(from, to);

        /* Evaluate */
        if(input == "exit")
            return;
        while(this->ctrl->submitMove(from, to))
        {
            std::cout<<"Coup interdit!"<<std::endl;
            this->getInputs(from, to);
        }


        /* Print */
        this->display();

        /* Loop */
    }
}

void IhmCli::setView(const Model& model)
{
    *this->model.get() = model;
}

void IhmCli::display()
{
    this->clear();
    this->model->getGrid().print();
}

void IhmCli::clear()
{
    std::cout<<"\e[2J";
}

void IhmCli::getInputs(unsigned& from, unsigned& to)
{
    std::string input;
    const std::regex expr("(\\d{1,2})\\,(\\d{1,2})");
    std::smatch matches;

    std::cout<<"\u001b[32mquixo\u001b[0m> ";
    std::cin>>input;

    std::regex_search(input, matches, expr);
    from = std::stoul(matches[1].str());
    to = std::stoul(matches[2].str());
}
