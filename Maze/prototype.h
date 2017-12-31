#pragma once
#include <stdio.h>


namespace ProtoType {

    class MapSite
    {
    public:

        virtual void Enter() = 0;

    private:

    };

    class Room : public MapSite {
    public:
        Room(int roomNO = 0) {
            _roomNumber = roomNO;
            printf("room : %d \n", _roomNumber);
        }


        Room* clone() {
            return new Room(_roomNumber);
        }
        void init(int n) {
            this->_roomNumber = n;
        }



        virtual void Enter() {}
    protected:
        int _roomNumber;
    };

    class Maze {
    public:
        Maze() {}
        Maze(Maze* m) {
            _maze = m;
        }

        Maze* clone() {
            printf("is clone Maze \n");
            return new Maze(_maze);
        }
        void AddRoom(Room*) {}
        Room* RoomNo(int) const {
            return 0;
        };
    private:
        Maze* _maze;
    };

    class MazeFactiory {
    public:
        MazeFactiory() {
            printf("creater MazeFactiory \n");
        }
        virtual Room* MakeRoom(int n)const {
            printf("MakeRoom \n");
            return new Room(n);
        }
        virtual Maze* MakeMaze()const {
            return new Maze;
        }
    };

    class MazeProtoTypeFactory : public MazeFactiory {
    public:

        MazeProtoTypeFactory(Room* r, Maze* m) {
            _r = r;
            _m = m;
        }

        virtual Room* MakeRoom(int n)const;
        virtual Maze* MakeMaze()const;
    private:
        Room* _r;
        Maze* _m;
    };


    class MazeGame
    {
    public:
        Maze* CreaterMaze(MazeFactiory& factory);
    private:

    };




}