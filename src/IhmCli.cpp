#include "IhmCli.h"

#include <iostream>

IhmCli::IhmCli()
{
    this->model = std::make_unique<Model>();
}

void IhmCli::run()
{
    // repl env
    this->display();
}

void IhmCli::setView(const Model& model)
{
    *this->model.get() = model;
}

void IhmCli::display()
{
    this->model->getGrid().print();
}