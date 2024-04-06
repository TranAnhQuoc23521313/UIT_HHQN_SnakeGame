#include "GamePlay.h"
#include <raylib.h>
#include <iostream>
#include"Snake.h"
#include<conio.h>
using namespace std;

void GamePlay::Start()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Grid Example");

    SetTargetFPS(60);

    Snake snake(GRID_SIZE / 2, GRID_SIZE / 2); 

    char key;

    while (!WindowShouldClose()) {
        if (_kbhit())
        {
            key = _getch();
            snake.SetDirection(key);

        }
        snake.Move();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        GamePlay::DrawGrid(GRID_ROWS, GRID_COLS, GRID_SIZE);

        
        snake.Draw(GRID_SIZE);

        
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
