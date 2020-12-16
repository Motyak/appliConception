#include "IhmSfml.h"

IhmSfml::IhmSfml() : Ihm()
{
    this->paused = false;
    this->selectedTileIndex = nullptr;
    this->buildGraphics();
}

/**
 * @brief Run the GUI (SFML graphics library)
 * 
 */
void IhmSfml::run()
{
    // event handling + rendering loop
    while (this->window->isOpen())
    {
        sf::Event evt;
        while (this->window->pollEvent(evt))
        {
            if (evt.type == sf::Event::Closed)
                this->window->close();

            if (evt.type == sf::Event::MouseButtonReleased)
            {
                if(this->paused) this->handleClickDuringPause();
                else
                {
                    if(this->insideGrid(evt.mouseButton.x, evt.mouseButton.y))
                        this->handleClickIn(evt);
                    else
                        this->handleClickOut();
                }
            }
        }
        this->display();
    }
}

/**
 * @brief Display the views
 * 
 */
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
    this->window->draw(*this->winner);
    this->window->display();
}

/**
 * @brief Set the view based on the model board
 * 
 * @param board The board to set to the view
 */
void IhmSfml::setView(Model::Board& board)
{
    // if the game is in pause, save the new board in storage
    // to restore it after the user unpaused
    if(this->paused)
        this->boardStorage = board;
    else
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
}

/**
 * @brief Set the view based on the model turn
 * 
 * @param turn The player whose turn it is to play
 */
void IhmSfml::setView(const Model::Player& turn)
{
    ;
}

/**
 * @brief Announce who the winner of the game is
 * 
 * @param winner The winner of the game
 */
void IhmSfml::announceWinner(const Model::Player& winner)
{
    if(winner == Model::Player::X)
        this->winner->setString("YOU WIN");
    else /* player O */
        this->winner->setString("YOU LOSE");

    this->paused = true;
}

/**
 * @brief Build all the graphic components
 * 
 */
void IhmSfml::buildGraphics()
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

    this->winner = std::make_unique<sf::Text>();
    this->winner->setFont(*this->font);
    this->winner->setCharacterSize(85);
    this->winner->setFillColor(sf::Color::White);
    this->winner->setPosition(230, 780);

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

/**
 * @brief Check if the coords are located in the grid
 * 
 * @param x x coord
 * @param y y coord
 * @return true if the coords are located in the grid
 * @return false otherwise
 */
bool IhmSfml::insideGrid(unsigned x, unsigned y)
{
    return  x > 139 && x < 760 && y > 139 && y < 760;
}

/**
 * @brief Exit the pause state
 * 
 */
void IhmSfml::exitPause()
{
    this->paused = false;
    this->setView(this->boardStorage);
    this->winner->setString("");
    
}

/* Event handlers*/

/**
 * @brief Handle click event during pause state
 * 
 */
void IhmSfml::handleClickDuringPause()
{
    this->exitPause();
}

/**
 * @brief Handle click inside grid
 * 
 * @param evt 
 */
void IhmSfml::handleClickIn(sf::Event evt)
{
    unsigned mouse_x = evt.mouseButton.x;
    unsigned mouse_y = evt.mouseButton.y;
    unsigned index_x = std::round((mouse_y - 140) / 125);
    unsigned index_y = std::round((mouse_x - 140) / 125);
    unsigned index = index_x * Model::Board::DIM + index_y;

    // if the user already clicked on a tile..
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

/**
 * @brief Handle click outside of the grid
 * 
 */
void IhmSfml::handleClickOut()
{
    if(this->selectedTileIndex.get())
    {
        this->selected[*this->selectedTileIndex.get()]->setColor(sf::Color(255, 255, 255, 0));
        this->selectedTileIndex.release();
    }
}