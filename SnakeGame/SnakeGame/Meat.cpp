#include "Meat.h"
#include <raylib.h>
#include <vector>
#include <raymath.h>

meat::meat(int cols, int rows, std::vector<Vector2> snake_body) {
    SetRandomPosition(cols, rows, snake_body);
    existenceTime = 0;
    color = RED;
}

Vector2 meat::GenerateRandomPosition(int cols, int rows) {
    float new_x = GetRandomValue(0, cols - 1);
    float new_y = GetRandomValue(0, rows - 1);
    return { new_x,new_y };
}

void meat::Draw() {
    DrawRectangle(position.x * GRID_SIZE, position.y * GRID_SIZE, GRID_SIZE, GRID_SIZE, color);
}

Vector2 meat::GetPosition() {
    return position;
}

int meat::GetExistenceTime() {
    return existenceTime;
}

void meat::IncrementExistenceTime() {
    existenceTime++;
}

bool meat::ElementInSnake(Vector2 meat_pos, std::vector<Vector2> snake_pos)
{
    for (unsigned int i = 0; i < snake_pos.size(); i++)
    {
        if (Vector2Equals(snake_pos[i], meat_pos))
        {
            return true;
        }
    }
    return false;
}

void meat::SetRandomPosition(int cols, int rows, std::vector<Vector2> snake_body)
{
    Vector2 new_position = GenerateRandomPosition(cols, rows);
    while (this->ElementInSnake(new_position, snake_body))
    {
        new_position = GenerateRandomPosition(cols, rows);
    }
    position = new_position;
}