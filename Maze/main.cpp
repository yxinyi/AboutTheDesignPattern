#pragma once
#include <stdio.h>

class A1 {
public:
    A1() {
        printf("A1() \n");
    }
    void printA() {
        printf("A1 \n");
    }
};

class A2: public A1 {
public:
    A2() {
        printf("A2() \n");

    }
    void printA() {
        printf("A2 \n");
    }
};

int main() {
    A1 a1;
    a1.printA();
    A2 a2;
    a2.printA();
    for (;;);
    return 0;
}