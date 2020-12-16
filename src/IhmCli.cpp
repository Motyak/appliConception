#include "IhmCli.h"

#include <iostream>
#include <regex>
#include <thread>
#include <chrono>

IhmCli::IhmCli()
{
    // has its own model
    this->model = std::make_unique<Model>();
}

/**
 * @brief Run the CLI (REPL environment)
 * 
 */
void IhmCli::run()
{
    std::string input = "";
    unsigned from, to;
    this->display();

    do
    {
        /* Read and Evaluate */
        std::cout<<"Quel sera votre prochain coup ?"<<std::endl;
        do
        {
            if(this->prompt(input) == "exit")
                return;
            this->getInputs(input, from, to);
        } while(!this->ctrl->submitMove(from, to));


        /* Print */
        this->display();


        /* Loop */
    } while(input != "exit");
}

/**
 * @brief Announce who the winner of the game is
 * 
 * @param winner The winner of the game
 */
void IhmCli::announceWinner(const Model::Player& winner)
{
    this->display();
    if(winner == Model::Player::X)
        std::cout<<"Joueur X a gagné!"<<std::endl;
    else /* Y */
        std::cout<<"Joueur Y a gagné!"<<std::endl;
    this->pause(2);
}

/**
 * @brief Set the view based on the model board
 * 
 * @param board The board to set to the view
 */
void IhmCli::setView(Model::Board& board)
{
    this->model->setGrid(board);
}

/**
 * @brief Set the view based on the model turn
 * 
 * @param turn The player whose turn it is to play
 */
void IhmCli::setView(const Model::Player& turn)
{
    this->model->setTurn(turn);
}

/**
 * @brief Display the views
 * 
 */
void IhmCli::display()
{
    this->clear();
    std::cout<<this->model->getGrid()<<std::endl;
}

/**
 * @brief Pause the interface
 * 
 * @param s The pause duration in seconds
 */
void IhmCli::pause(unsigned s)
{
    std::this_thread::sleep_for(std::chrono::seconds(s));
}

/**
 * @brief Clear the view using ANSI escape character
 * 
 */
void IhmCli::clear()
{
    std::cout<<"\e[2J";
}

/**
 * @brief Parse the start and end index from the user command
 * 
 * @param input user input command
 * @param from start index
 * @param to end index
 */
void IhmCli::getInputs(const std::string& input, unsigned& from, unsigned& to)
{
    const std::regex expr("(\\d{1,2})\\,(\\d{1,2})");
    std::smatch matches;

    std::regex_search(input, matches, expr);
    from = std::stoul(matches[1].str());
    to = std::stoul(matches[2].str());
}

/**
 * @brief Ask user for a command
 * 
 * @param input the user command
 * @return std::string the user command
 */
std::string IhmCli::prompt(std::string& input)
{
    std::cout<<"\u001b[32mquixo\u001b[0m> ";
    std::cin>>input;
    return input;
}
