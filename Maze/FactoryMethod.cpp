#pragma once
#include "FactoryMethod.h"


Maze* FactoryMethod::MazeGame::CreateMaze() {
    Maze* aMaze = MakeMaze();
    Room* r1 = MakeRoom(1);
    Room* r2 = MakeRoom(2);
    printf("r1 no :%d \n", r1->GetMyRoomNo());
    printf("r2 no :%d \n", r2->GetMyRoomNo());
    Door* aDoor = MakeDoor(r1, r2);
    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, MakeWall());
    r1->SetSide(East, aDoor);
    r1->SetSide(South, MakeWall());
    r1->SetSide(West, MakeWall());


    r2->SetSide(North, MakeWall());
    r2->SetSide(East, MakeWall());
    r2->SetSide(South, MakeWall());
    r2->SetSide(West, aDoor);
    return aMaze;
}