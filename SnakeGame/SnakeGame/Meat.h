#pragma once
#include <raylib.h>
#include <vector>

#define GRID_SIZE 30

typedef struct {
    int x;
    int y;
} Pnt;

class meat
{
private:
    Pnt position; 
    int existenceTime; 
    Color color; 
public:
    meat(int, int);
    void SetRandomPosition(int, int);
    void Draw();
    Pnt GetPosition();
    int GetExistenceTime();
    void IncrementExistenceTime();
    void ResetExistenceTime() {
        existenceTime = 0;
    }
};

