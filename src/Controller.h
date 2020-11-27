#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "View.h"

#include <memory>
#include <SFML/Graphics.hpp>

class View;

class Controller
{
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<Model> model;
    std::unique_ptr<View> view;

  public:
    Controller();
    virtual ~Controller();
	std::unique_ptr<sf::RenderWindow> getWindow();
    void run();
};
#endif