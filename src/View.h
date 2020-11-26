#ifndef VIEW_H
#define VIEW_H

#include "Model.h"

#include <memory>
#include <SFML/Graphics.hpp>

class View
{
    std::shared_ptr<Model> model;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<sf::CircleShape> circle;

  public:
    View(std::shared_ptr<Model> model, std::shared_ptr<sf::RenderWindow> window);

    void draw();
};
#endif