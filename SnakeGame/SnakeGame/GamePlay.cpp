#include "GamePlay.h"
#include <raylib.h>
#include <iostream>
using namespace std;

void GamePlay::Start()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Grid Example");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        GamePlay::DrawGrid(GRID_ROWS, GRID_COLS, GRID_SIZE);

        EndDrawing();
    }

    CloseWindow();
}

void GamePlay::DrawGrid(int rows, int cols, int cellSize)
{
   for (int i = 0; i < rows; i++) {
        DrawLine(0, i * cellSize, cols * cellSize, i * cellSize, LIGHTGRAY);
   }
   for (int j = 0; j < cols; j++) {
        DrawLine(j * cellSize, 0, j * cellSize, rows * cellSize, LIGHTGRAY);
   }

}
