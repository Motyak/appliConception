#include "IhmSfml.h"

IhmSfml::IhmSfml()
{
    this->ctrl = std::make_unique<Controller>(this, new Model());

    this->window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(200, 200),
        "SFML works!"
    );

    // example view
    this->circle = std::make_unique<sf::CircleShape>(100.f);
    this->circle->setFillColor(sf::Color::Green);
}

void IhmSfml::run()
{
    // event handling + rendering loop
    while (this->window->isOpen())
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }
        this->display();
    }
}

void IhmSfml::display()
{
    this->window->clear();
    this->window->draw(*this->circle);
    this->window->display();
}