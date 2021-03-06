#ifndef IHMSFML_H
#define IHMSFML_H

#include "Ihm.h"

#include <SFML/Graphics.hpp>

/**
 * @brief Is responsible for displaying the views and handling user events
 * 
 */
class IhmSfml : public Ihm
{
    bool paused;
    Model::Board boardStorage;
    std::unique_ptr<unsigned> selectedTileIndex;

    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Text> tiles[25];
    std::unique_ptr<sf::Texture> backgroundTex;
    std::unique_ptr<sf::Sprite> background;
    std::unique_ptr<sf::Texture> gridBackgroundTex;
    std::unique_ptr<sf::Sprite> gridBackground;
    std::unique_ptr<sf::Font> font;
    std::unique_ptr<sf::CircleShape> board;
    std::unique_ptr<sf::Texture> selectedTex;
    std::unique_ptr<sf::Sprite> selected[25];
    std::unique_ptr<sf::Texture> hoverTex;
    std::unique_ptr<sf::Sprite> hover[25];
    std::unique_ptr<sf::Text> winner;

    void handleClickDuringPause();
    void handleClickIn(sf::Event evt);
    void handleClickOut();

    void buildGraphics();
    void exitPause();
    bool insideGrid(unsigned x, unsigned y);

  public:
    IhmSfml();
    void run();
    void setView(Model::Board& board);
    void setView(const Model::Player& turn);
    void display();
    void announceWinner(const Model::Player& winner);
};

#endif