#include "Model.h"

#include <iostream>

// g++ -o bin/main src/Model.cpp src/main.cpp
int main()
{
    Model::Board grid(3);
    grid[0] = Model::Tile::X;
    grid[4] = Model::Tile::X;
    grid[8] = Model::Tile::X;
    grid.print();

    return 0;
}