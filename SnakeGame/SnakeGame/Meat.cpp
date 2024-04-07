#include "Meat.h"
#include <raylib.h>
#include <vector>

meat::meat(int cols, int rows) {
    SetRandomPosition(cols, rows);
    existenceTime = 0;
    color = RED;
}

void meat::SetRandomPosition(int cols, int rows) {
    position.x = GetRandomValue(0, cols - 1); 
    position.y = GetRandomValue(0, rows - 1); 
}

void meat::Draw() {
    DrawRectangle(position.x * GRID_SIZE, position.y * GRID_SIZE, GRID_SIZE, GRID_SIZE, color);
}

Pnt meat::GetPosition() {
    return position;
}

int meat::GetExistenceTime() {
    return existenceTime;
}

void meat::IncrementExistenceTime() {
    existenceTime++;
}