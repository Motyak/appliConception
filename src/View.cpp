#include "View.h"

View::View(Controller* ctrl)
{
    this->ctrl = std::unique_ptr<Controller>(ctrl);
    this->circle = std::make_unique<sf::CircleShape>(100.f);
    this->circle->setFillColor(sf::Color::Green);
}
    
void View::draw()
{
    this->ctrl->getWindow()->draw(*this->circle);
}