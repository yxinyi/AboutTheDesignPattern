#pragma once
#include "prototype.h"

using namespace ProtoType;
namespace ProtoType {
    Room*  MazeProtoTypeFactory::MakeRoom(int n)const {
        Room* tmpRoom = _r->clone();
        tmpRoom->init(n);
        return tmpRoom;
    }
    Maze*  MazeProtoTypeFactory::MakeMaze()const {
        return _m->clone();
    }

    Maze* MazeGame::CreaterMaze(MazeFactiory& factory) {
        Maze* maze = factory.MakeMaze();
        Room* room = factory.MakeRoom(1);
        maze->AddRoom(room);
        return maze;
    }
}