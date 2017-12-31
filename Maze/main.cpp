#pragma once
#include <stdio.h>
#include "builder.h"
#include "FactoryMethod.h"
//#include "AbstractFactory.cpp"

int main() {

    ////AbstractFactory Mode
    //AbstractFactory::MazeGame maze;
    //AbstractFactory::SkyMazeFactiory skyFactiory;
    //maze.CreaterMaze(skyFactiory);
    //AbstractFactory::EnchantedMazeFactiory enchantedFactiory;
    //maze.CreaterMaze(enchantedFactiory);
    //for (;;);
    //return 0;
    


    // Builder Mode
    //Maze* maze  = 0;
    //Builder::MazeGame mazeGame ;
    //Builder::StandardMazeBuilder mazeBuileder;
    //maze = mazeGame.CreateMaze(mazeBuileder);
    //for (;;);
    //return 0;

    //FactoryMethod
    Maze* maze  = 0;
    FactoryMethod::BoomMazeGame mazeGame ;
    maze = mazeGame.CreateMaze();
    for (;;);
    return 0;
}
