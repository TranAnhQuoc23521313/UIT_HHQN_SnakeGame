#include "GamePlay.h"
#include <raylib.h>
#include"Snake.h"

#define CHOOSE_SCREEN_WIDTH 560
#define CHOOSE_SCREEN_HEIGHT 280
#define GRID_SIZE 30

Rectangle smallButton = { 20, 20, 100, 40 };
Rectangle mediumButton = { 140, 20, 100, 40 };
Rectangle largeButton = { 260, 20, 100, 40 };

GridSize currentGridSize = MEDIUM;

bool buttonsVisible = true;


void GamePlay::Choose_Mode_GamePlay()
{
    InitWindow(CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT, "SNAKE GAME");

    SetTargetFPS(60);
    int HEIGHT_GAME_SCREEN = 0;
    int WIDTH_GAME_SCREEN = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //if (!buttonsVisible) { // Nếu buttonsVisible là false, chỉ hiển thị lưới
        //    if (currentGridSize == SMALL) {
        //        HEIGHT_GAME_SCREEN = 560;
        //        WIDTH_GAME_SCREEN = 720;
        //        break;
        //    }
        //    else if (currentGridSize == MEDIUM) {
        //        HEIGHT_GAME_SCREEN = 720;
        //        WIDTH_GAME_SCREEN = 1280;
        //        break;
        //    }
        //    else if (currentGridSize == LARGE) {
        //        HEIGHT_GAME_SCREEN = 980;
        //        WIDTH_GAME_SCREEN = 1820;
        //        break;
        //    }
        //}

        GamePlay::DrawChooseButtonMode(); 

        if (buttonsVisible) { // Kiểm tra nút nào được nhấn và cập nhật kích thước lưới
            if (CheckCollisionPointRec(GetMousePosition(), smallButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = SMALL;
                buttonsVisible = false; // Ẩn các nút sau khi nút đã được nhấn
                HEIGHT_GAME_SCREEN = 560;
                WIDTH_GAME_SCREEN = 720;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), mediumButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = MEDIUM;
                buttonsVisible = false;
                HEIGHT_GAME_SCREEN = 720;
                WIDTH_GAME_SCREEN = 1280;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), largeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = LARGE;
                buttonsVisible = false;
                HEIGHT_GAME_SCREEN = 980;
                WIDTH_GAME_SCREEN = 1820;
            }
        }

        EndDrawing();
    }
    CloseWindow();
    GamePlay::Start(WIDTH_GAME_SCREEN, HEIGHT_GAME_SCREEN);
    return;
}


void GamePlay::DrawChooseButtonMode()
{

    if (buttonsVisible) { // Chỉ vẽ nút khi biến buttonsVisible là true
        DrawRectangleRec(smallButton, LIGHTGRAY);
        DrawRectangleRec(mediumButton, LIGHTGRAY);
        DrawRectangleRec(largeButton, LIGHTGRAY);

        DrawText("Small", smallButton.x + 10, smallButton.y + 10, 20, BLACK);
        DrawText("Medium", mediumButton.x + 10, mediumButton.y + 10, 20, BLACK);
        DrawText("Large", largeButton.x + 10, largeButton.y + 10, 20, BLACK);
    }
}

void GamePlay::Start(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    SetTargetFPS(60);

    int GRID_ROWS = SCREEN_HEIGHT / GRID_SIZE;
    int GRID_COLS = SCREEN_WIDTH / GRID_SIZE;

    Snake snake(GRID_SIZE / 2, GRID_SIZE / 2);//chinh sua
    char key;

    while (!WindowShouldClose()) {
        if (_kbhit())//chinh sua
        {
            key = _getch();
            snake.SetDirection(key);

        }
        snake.Move();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        GamePlay::DrawGrid(GRID_ROWS, GRID_COLS, GRID_SIZE);

        snake.Draw(GRID_SIZE);//chinh sua

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
