#pragma once
#include "MazeBasic.cpp"

namespace FactoryMethod {
    class MazeGame {
    public:
        Maze* CreateMaze();

        virtual Maze* MakeMaze() const {
            return new Maze;
        }
        virtual Room* MakeRoom(int roomNo)const {
            return new Room(roomNo);
        }
        virtual Wall* MakeWall()const {
            return new Wall;
        }
        virtual Door* MakeDoor(Room* r1, Room * r2)const {
            return new Door(r1, r2);
        }
    };


    class BoomRoom : public Room {
    public:
        BoomRoom(int roomNo = 0) {
            _roomNumber = roomNo;
            
            printf("create BoomRoom :%d \n", _roomNumber);
        }

        int GetMyRoomNo() {
            printf("BoomRoom: GetMyRoomNo  \n");
            return _roomNumber;
        }
    private:
        int _roomNumber;
    };
    class BoomMazeGame : public MazeGame {
    public:
        BoomMazeGame() {

        }
        virtual Room* MakeRoom(int roomNo)const {
            BoomRoom* tmpRoom = new BoomRoom(roomNo);
            tmpRoom->GetMyRoomNo();
            return tmpRoom;
        }
    };
}