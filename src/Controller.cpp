#include "Controller.h"

Controller::Controller()
{
    this->window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(200, 200),
        "SFML works!"
    );
    this->model = std::make_shared<Model>();
    this->view = std::make_shared<View>(this->model, this->window);
}

Controller::~Controller() 
{
    this->window->close();
}

void Controller::run()
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

        this->window->clear();
        this->view->draw();
        this->window->display();
    }
}