#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "View.h"

#include <memory>
#include <SFML/Graphics.hpp>

class Controller
{
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<Model> model;
    std::shared_ptr<View> view;

  public:
    Controller();
    virtual ~Controller();

    void run();
};
#endif