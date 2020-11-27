#include "Controller.h"

Controller::Controller()
{
    this->window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(200, 200),
        "SFML works!"
    );
    this->model = std::make_unique<Model>();
    this->view = std::make_unique<View>(this);
}

Controller::~Controller() 
{
    this->window->close();
}

std::unique_ptr<sf::RenderWindow> Controller::getWindow()
{
    return std::move(this->window);
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