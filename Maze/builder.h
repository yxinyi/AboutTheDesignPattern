#pragma once
#include <stdio.h>
#include "MazeBasic.cpp"

namespace Builder {

    class MazeBuilder {
    public:
        virtual void BuilderMaze() {}
        virtual void BuilderRoom(int roomNo) {}
        virtual void BuilderDoor(int r1, int r2);
        virtual Maze* GetMaze() { return 0; }
    };

    class MazeGame
    {
    public:
        MazeGame();
        Maze* CreateMaze(MazeBuilder & builder);
    private:

    };


    class StandardMazeBuilder : public MazeBuilder {
    public:
        StandardMazeBuilder();

        virtual void BuilderMaze();
        virtual void BuilderRoom(int roomNo);
        virtual void BuilderDoor(int r1, int r2);

        virtual Maze* GetMaze();

    private:
        Direction commonWall(int r1, int r2);
        Maze* _currentMaze;
    };
}