#ifndef VIEW_H
#define VIEW_H

#include "Controller.h"

#include <memory>
#include <SFML/Graphics.hpp>

class Controller;

class View
{
    std::unique_ptr<Controller> ctrl;
    std::unique_ptr<sf::CircleShape> circle;

  public:
    View(Controller* ctrl);
    void draw();
};
#endif