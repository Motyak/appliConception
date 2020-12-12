#ifndef IHMSFML_H
#define IHMSFML_H

#include "Ihm.h"

#include <SFML/Graphics.hpp>

class IhmSfml : public Ihm
{
    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::CircleShape> circle;

  public:
    IhmSfml();
    void run();
    void setView(const Model& model);
    void display();
};

#endif