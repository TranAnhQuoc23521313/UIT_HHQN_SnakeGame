#pragma once 

#define SCREEN_WIDTH 1820
#define SCREEN_HEIGHT 980
#define GRID_SIZE 30
#define GRID_ROWS (SCREEN_HEIGHT / GRID_SIZE)
#define GRID_COLS (SCREEN_WIDTH / GRID_SIZE)

struct Point {
    int x, y;
};

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Logic
{
private:
    bool gameOver;
    Point head, meat;
    int score;
    Direction dir;
public:
    Logic();
    void Draw();
    void Input();
    void LOGIC();
    void Run();
};

