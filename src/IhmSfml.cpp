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

    this->selectedTex = std::make_unique<sf::Texture>();
    this->selectedTex->loadFromFile("res/img/selected.jpg");

    for(int x = 0 ; x < Model::Board::DIM ; ++x)
    {
        for(int y = 0 ; y < Model::Board::DIM ; ++y)
        {
            unsigned index = x * Model::Board::DIM + y;
            this->tiles[index] = std::make_unique<sf::Text>();
            this->tiles[index]->setFont(*this->font);
            this->tiles[index]->setString(" ");
            this->tiles[index]->setCharacterSize(85);
            this->tiles[index]->setFillColor(sf::Color::Black);
            this->tiles[index]->setPosition(169 + 125 * x, 145 + 125 * y);

            this->selected[index] = std::make_unique<sf::Sprite>(*this->selectedTex);
            this->selected[index]->setColor(sf::Color(255, 255, 255, 0));
            this->selected[index]->setPosition(138 + 125 * y, 138 + 125 * x);
        }
    }
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

            if (event.type == sf::Event::MouseButtonReleased)
            {
                unsigned mouse_x = event.mouseButton.x;
                unsigned mouse_y = event.mouseButton.y;
                if(event.mouseButton.x > 139 && event.mouseButton.x < 760 &&
                event.mouseButton.y > 139 && event.mouseButton.y < 760)
                {
                    unsigned index_x = std::round((mouse_y - 140) / 125);
                    unsigned index_y = std::round((mouse_x - 140) / 125);
                    unsigned index = index_x * Model::Board::DIM + index_y;
                    std::cout<<"index = "<<index<<"<=>("<<index_x<<";"<<index_y<<")"<<std::endl;

                    if(this->selectedTileIndex.get())
                    {
                        this->ctrl->submitMove(*this->selectedTileIndex.get(), index);
                        this->selected[*this->selectedTileIndex.get()]->setColor(sf::Color(255, 255, 255, 0));
                        this->selectedTileIndex.release();
                    }
                    else
                    {
                        this->selectedTileIndex.reset(new unsigned(index));
                        this->selected[index]->setColor(sf::Color(255, 255, 255, 150));
                    }
                }
                else
                {
                    std::cout<<"clic out"<<std::endl;
                    if(this->selectedTileIndex.get())
                    {
                        this->selected[*this->selectedTileIndex.get()]->setColor(sf::Color(255, 255, 255, 0));
                        this->selectedTileIndex.release();
                    }
                }
            }
        }
        this->display();
    }
}

void IhmSfml::setView(Model::Board& board)
{
    std::map<Model::Tile,std::string> map {
        {Model::Tile::EMPTY, " "},
        {Model::Tile::X, "X"},
        {Model::Tile::O, "O"}
    };
    for(int x = 0 ; x < Model::Board::DIM ; ++x)
    {
        for(int y = 0 ; y < Model::Board::DIM ; ++y)
        {
            sf::Text& t = *this->tiles[x * Model::Board::DIM + y].get();
            t.setString(map[board[y * Model::Board::DIM + x]]);
        }
    }
}

void IhmSfml::setView(const Model::Player& turn)
{
    ;
}

void IhmSfml::display()
{
    this->window->clear();
    this->window->draw(*this->background);
    this->window->draw(*this->board);
    this->window->draw(*this->gridBackground);
    for(int i = 0 ; i < Model::Board::SIZE ; ++i)
    {
        this->window->draw(*this->tiles[i]);
        this->window->draw(*this->selected[i]);
    }
    this->window->display();
}

void IhmSfml::announceWinner(const Model::Player& winner)
{
    
}