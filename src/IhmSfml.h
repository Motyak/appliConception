#ifndef IHMSFML_H
#define IHMSFML_H

#include "Controller.h"

#include <memory>
#include <SFML/Graphics.hpp>

class IhmSfml : public Ihm
{
    std::unique_ptr<Controller> ctrl;
    std::unique_ptr<sf::RenderWindow> window;

    std::unique_ptr<sf::CircleShape> circle;

  public:
    IhmSfml();
    void run();
    void display();
};

#endif