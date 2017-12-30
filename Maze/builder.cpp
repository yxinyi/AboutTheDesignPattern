#pragma once
#include "MazeBasic.cpp"
#include "builder.h"


namespace Builder {

    void MazeBuilder::BuilderDoor(int r1, int r2) {
        printf("make basic door \n"); 
    }

    MazeGame::MazeGame() {
    
    }
    Maze * MazeGame::CreateMaze(MazeBuilder & builder) {
        builder.BuilderMaze();
        builder.BuilderRoom(1);
        builder.BuilderRoom(2);
        builder.BuilderDoor(1, 2);
        return builder.GetMaze  ();
    }
    


    StandardMazeBuilder::StandardMazeBuilder() {
        _currentMaze = 0;
    }
    
    void StandardMazeBuilder::BuilderMaze() {
        _currentMaze = new Maze();
        printf("StandardMazeBuilder::BuilderMaze \n");
    }
    void StandardMazeBuilder::BuilderRoom(int roomNo) {
        if (!_currentMaze->RoomNo(roomNo)) {
            Room* room = new Room;
            room->SetSide(North, room);
            room->SetSide(South, room);
            room->SetSide(East, room);
            room->SetSide(West, room);
            _currentMaze->AddRoom(room);
            printf("StandardMazeBuilder::BuilderRoom \n");
        }
    }
    void StandardMazeBuilder::BuilderDoor(int r1, int r2) {
        Room* room1 = _currentMaze->RoomNo(r1);
        Room* room2 = _currentMaze->RoomNo(r2);
        Door* d = new Door(room1, room2);
        room1->SetSide(commonWall(r1, r2), room1);
        room2->SetSide(commonWall(r2, r1), room2);
        printf("StandardMazeBuilder::BuilderDoor \n");
    }
    
    Maze* StandardMazeBuilder::GetMaze() { return _currentMaze; }
    
    Direction StandardMazeBuilder::commonWall(int r1, int r2) {
        if (r1 > r2) {
            return North;
        }
        return West;
    }





}