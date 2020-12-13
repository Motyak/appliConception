#include "IhmSfml.h"

IhmSfml::IhmSfml() : Ihm()
{
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

void IhmSfml::setView(const Model::Board& board)
{

}

void IhmSfml::setView(const Model::Player& turn)
{

}

void IhmSfml::display()
{
    this->window->clear();
    this->window->draw(*this->circle);
    this->window->display();
}

void IhmSfml::announceWinner(const Model::Player& winner)
{
    
}