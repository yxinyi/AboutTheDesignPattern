#pragma once
#include <stdio.h>

enum Direction {
    North,
    South,
    East,
    West
};

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
        printf("creater room %d \n", _roomNumber);
    }

    int GetMyRoomNo() {
        printf("Room: GetMyRoomNo  : %d \n", _roomNumber);
        return _roomNumber;
    }

    MapSite* GetSide(Direction theDirection) const {
        return _sides[theDirection];
    }
    void SetSide(Direction theDirection, MapSite* a) {
        _sides[theDirection] = a;
    }
    virtual void Enter() {}
protected:
    MapSite* _sides[4];
    int _roomNumber;
};

class Wall : public MapSite
{
public:
    Wall() {
        printf("creater Wall \n");
    }
    virtual void Enter() {}
};

class  Door : public MapSite
{
public:
    Door(Room* r1 = 0, Room * r2 = 0) {
        printf("creater Door \n");
    }
    void Enter() {}
    Room* OtherSideFrom(Room* room) {

    }
private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

class Maze {
public:
    Maze() {}
    void AddRoom(Room*) {}
    Room* RoomNo(int) const {
        return 0;
    };
private:
};
