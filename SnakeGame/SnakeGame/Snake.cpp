#include "Snake.h"
#include <raylib.h>
#include <iostream>
#include <conio.h>
using namespace std;

void Snake::Move() 
{
    static int frameCount = 0;
    const int moveSpeed = 10; 

    if (frameCount >= moveSpeed) {
        for (int i = SNAKE_LENGTH - 1; i > 0; --i) {
            segments[i] = segments[i - 1];
        }
        segments[0].x += this->directionX;
        segments[0].y += this->directionY;

        frameCount = 0; 
    }
    else {
        frameCount++; 
    }
}

void Snake::Draw(int cellSize) {
    for (int i = 0; i < SNAKE_LENGTH; ++i) {
        DrawRectangle(segments[i].x * cellSize, segments[i].y * cellSize, cellSize, cellSize, RED);
    }
}

void Snake::SetDirection(char key)
{
    switch (key) {
    case 's':
        if (directionY != 1) {
            directionX = 0;
            directionY = -1;
        }
        std::cout << key;
        break;
    case 'a':
        if (directionX != 1) {
            directionX = -1;
            directionY = 0;
        }
        break;
    case 'w':
        if (directionY != -1) {
            directionX = 0;
            directionY = 1;
        }
        break;
    case 'd':
        if (directionX != -1) {
            directionX = 1;
            directionY = 0;
        }
        break;
    }
}