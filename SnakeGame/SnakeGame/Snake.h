#pragma once
#include <raylib.h>
#include<conio.h>

const int SNAKE_LENGTH = 2;

class Snake
{
private:
    struct Vector2 {
        int x, y;
    };
    Vector2 segments[SNAKE_LENGTH];
    int directionX, directionY;
public:
    Snake(int startX, int startY) {
        segments[0] = { startX, startY };
        segments[1] = { startX - 1, startY };
        directionX = 1;
        directionY = 0;
    }
    void Move();
    void Draw(int);
    void SetDirection(char);
};



