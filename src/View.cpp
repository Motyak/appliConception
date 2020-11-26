#include "View.h"

View::View(std::shared_ptr<Model> model, std::shared_ptr<sf::RenderWindow> window)
{
    this->model = model;
    this->window = window;
    this->circle = std::make_shared<sf::CircleShape>(100.f);
    this->circle->setFillColor(sf::Color::Green);
}
    
void View::draw()
{
    this->window->draw(*this->circle);
}