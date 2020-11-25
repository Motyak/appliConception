#include "Model.h"

#include <iostream>

// g++ -o bin/main src/Model.cpp src/main.cpp
int main()
{
    Model m;
    Model::Board& grid = m.getGrid();
    grid[0] = Model::Tile::X;
    grid[5] = Model::Tile::X;
    grid[24] = Model::Tile::X;
    grid.print();
    grid.clear();
    std::cout<<"------------------"<<std::endl;
    grid.print();

    return 0;
}