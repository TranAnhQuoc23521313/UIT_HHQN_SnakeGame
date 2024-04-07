#pragma once
#include <raylib.h>
#include <vector>
#include"meat.h"

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
public:
    Snake(int, int , int , int );
    void Move(int,int,int&,meat&);
    void Draw();
    void ChangeDirection(int , int);
    bool CheckSelfCollision() const;
    friend class GamePlay;
};