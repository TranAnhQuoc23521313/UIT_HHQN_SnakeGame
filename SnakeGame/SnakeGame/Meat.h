#pragma once
#include <raylib.h>
#include <vector>

#define GRID_SIZE 30

class meat
{
private:
    Vector2 position;
    int existenceTime;
    Color color;
public:
    meat(int, int, std::vector<Vector2>);
    Vector2 GenerateRandomPosition(int, int);
    void SetRandomPosition(int, int, std::vector<Vector2>);
    void Draw();
    Vector2 GetPosition();
    int GetExistenceTime();
    void IncrementExistenceTime();
    void ResetExistenceTime() {
        existenceTime = 0;
    }
    bool ElementInSnake(Vector2 Pos_meat, std::vector<Vector2> snake);
};

