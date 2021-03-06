#pragma once
#include <stdio.h>
#include "MazeBasic.cpp"

namespace AbstractFactory {


    class MazeFactiory {
    public:
        MazeFactiory() {
            printf("creater MazeFactiory \n");
        }
        virtual Maze* MakeMaze()const {
            return new Maze;
        }
        virtual Wall* MakeWall()const {
            return new Wall;
        }
        virtual Room* MakeRoom(int n)const {
            printf("MakeRoom \n");
            return new Room(n);
        }
        virtual Door* MakeDoor(Room* r1, Room* r2)const {
            return new Door(r1, r2);
        }
    };

    class EnchantedRoom : public Room
    {

    public:
        EnchantedRoom(int roomNO = 0)
        {
            printf("creater EnchantRoom \n");
        }

        MapSite* GetSide(Direction) const {}
        void SetSide(Direction, MapSite*) {}
        virtual void Enter() {}
    private:
        MapSite* _sides[4];
        int _roomNumber;

    };


    class EnchantedMazeFactiory : public MazeFactiory
    {
    public:
        EnchantedMazeFactiory() {
            printf("creater EnchantedMazeFactiory \n");
        }
        virtual Room* MakeRoom(int n)const {
            printf("MakeEnchantedRoom \n");
            return new EnchantedRoom(n);
        }
    private:

    };


    class SkyRoom : public Room
    {

    public:
        SkyRoom(int roomNO = 0)
        {
            printf("creater SkyRoom \n");
        }

        MapSite* GetSide(Direction) const;
        void SetSide(Direction, MapSite*);
        virtual void Enter() {}
    private:
        MapSite* _sides[4];
        int _roomNumber;

    };


    class SkyMazeFactiory : public MazeFactiory
    {
    public:
        SkyMazeFactiory() {
            printf("creater SkyMazeFactiory \n");
        }
        virtual Room* MakeRoom(int n)const {
            return new SkyRoom(n);
        }
    private:

    };


    class MazeGame
    {
    public:
        Maze* CreaterMaze(MazeFactiory& factory);
    private:

    };


    Maze* MazeGame::CreaterMaze(MazeFactiory& factory) {
        Maze* aMaze = factory.MakeMaze();
        Room* r1 = factory.MakeRoom(1);
        Room* r2 = factory.MakeRoom(2);
        Door* aDoor = factory.MakeDoor(r1, r2);
        aMaze->AddRoom(r1);
        aMaze->AddRoom(r2);

        r1->SetSide(North, factory.MakeWall());
        r1->SetSide(East, aDoor);
        r1->SetSide(South, factory.MakeWall());
        r1->SetSide(West, factory.MakeWall());


        r2->SetSide(North, factory.MakeWall());
        r2->SetSide(East, factory.MakeWall());
        r2->SetSide(South, factory.MakeWall());
        r2->SetSide(West, aDoor);
        return aMaze;
    }
}

//int main() {
//}