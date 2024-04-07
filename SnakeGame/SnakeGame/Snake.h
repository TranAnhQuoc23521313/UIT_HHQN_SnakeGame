#pragma once
#include <raylib.h>
#include <vector>
#include"meat.h"
#include "GamePlay.h"

#define GRID_SIZE 30
//#define GRID_ROWS 20
//#define GRID_COLS 20

typedef struct {
    int x;
    int y;
} Point;

class Snake {
private:
    std::vector<Point> body;
    int dx; // Hướng di chuyển theo trục X
    int dy; // Hướng di chuyển theo trục Y
    int SCC_WIDTH;
    int score;
    int Speed = 8;
    int old_speed = 0;
public:
    Snake(int, int , int , int );
    void Move(int,int,int&,meat&);
    void Draw();
    void ChangeDirection(int , int);
    bool CheckSelfCollision() const;
    void Set_SCR_WIDTH(int SCR_WIDTH)
    {
        this->SCC_WIDTH = SCR_WIDTH;
    }

    int GetScore()
    {
        return this->score;
    }

    int GetSpeed()
    {
        return this->Speed;
    }

    void DrawScore();
};