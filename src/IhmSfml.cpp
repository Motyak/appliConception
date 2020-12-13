#include "IhmSfml.h"

IhmSfml::IhmSfml() : Ihm()
{
    this->window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(900, 900),
        "Quixo",
        sf::Style::Titlebar | sf::Style::Close
    );

    this->board = std::make_unique<sf::CircleShape>(450.f);
    this->board->setFillColor(sf::Color(40, 10, 10));

    this->backgroundTex = std::make_unique<sf::Texture>();
    this->backgroundTex->loadFromFile("res/img/background.jpg");

    this->background = std::make_unique<sf::Sprite>(*this->backgroundTex);

    this->gridBackgroundTex = std::make_unique<sf::Texture>();
    this->gridBackgroundTex->loadFromFile("res/img/grid.jpg");

    this->gridBackground = std::make_unique<sf::Sprite>(*this->gridBackgroundTex);
    this->gridBackground->setPosition(140, 140);

    this->font = std::make_unique<sf::Font>();
    this->font->loadFromFile("res/fonts/segoescb.ttf");

    this->text = std::make_unique<sf::Text>();
    this->text->setFont(*this->font);
    this->text->setString("X O");
    this->text->setCharacterSize(96);
    this->text->setFillColor(sf::Color::White);
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
    // for(const auto& c : this->grid)
    //     this->window->draw(*c);
    this->window->draw(*this->background);
    this->window->draw(*this->board);
    this->window->draw(*this->gridBackground);
    this->window->draw(*this->text);
    this->window->display();
}

void IhmSfml::announceWinner(const Model::Player& winner)
{
    
}