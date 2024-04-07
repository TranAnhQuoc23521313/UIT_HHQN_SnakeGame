#include "GamePlay.h"
#include <raylib.h>
#include "Snake.h"
#include"meat.h"
#include<string>

#define CHOOSE_SCREEN_WIDTH 560
#define CHOOSE_SCREEN_HEIGHT 280
#define GRID_SIZE 30

Rectangle smallButton = { 20, 20, 100, 40 };
Rectangle mediumButton = { 140, 20, 100, 40 };
Rectangle largeButton = { 260, 20, 100, 40 };

GridSize currentGridSize = MEDIUM;

bool buttonsVisible = true;

int GamePlay::score = 0;

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
                break;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), mediumButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = MEDIUM;
                buttonsVisible = false;
                HEIGHT_GAME_SCREEN = 720;
                WIDTH_GAME_SCREEN = 1280;
                break;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), largeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = LARGE;
                buttonsVisible = false;
                HEIGHT_GAME_SCREEN = 980;
                WIDTH_GAME_SCREEN = 1820;
                break;
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

    SetTargetFPS(8);

    int GRID_ROWS_SCREEN = SCREEN_HEIGHT / GRID_SIZE;
    int GRID_COLS_SCREEN = SCREEN_WIDTH / GRID_SIZE;
    int FrameCount = 8;

    this->setSCR_WIDTH(SCREEN_WIDTH);
   
    //Snake::GRID_COLS = GRID_COLS_SCREEN;
    //Snake::GRID_ROWS = GRID_ROWS_SCREEN;
    Snake snake(GRID_COLS_SCREEN / 2, GRID_ROWS_SCREEN / 2, 1, 0);

    meat MEAT(GRID_COLS_SCREEN, GRID_ROWS_SCREEN);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
       
        if (IsKeyPressed(KEY_RIGHT)) {
            snake.ChangeDirection(1, 0); // Thay đổi hướng sang phải
        }
        else if (IsKeyPressed(KEY_LEFT)) {
            snake.ChangeDirection(-1, 0); // Thay đổi hướng sang trái
        }
        else if (IsKeyPressed(KEY_UP)) {
            snake.ChangeDirection(0, -1); // Thay đổi hướng lên trên
        }
        else if (IsKeyPressed(KEY_DOWN)) {
            snake.ChangeDirection(0, 1); // Thay đổi hướng xuống dưới
        }

        snake.Move(GRID_COLS_SCREEN, GRID_ROWS_SCREEN,FrameCount,MEAT); // Di chuyển con rắn
        snake.Draw(); // Vẽ con rắn

        MEAT.Draw();

        // Kiểm tra va chạm với thân mình
        if (snake.CheckSelfCollision()) {
            // Nếu có va chạm, kết thúc trò chơi
            break;
        }

        // Cập nhật thời gian tồn tại của mieng thit
        MEAT.IncrementExistenceTime();

        // Kiểm tra xem quả táo đã tồn tại quá thời gian cho phép hay chưa
        if (MEAT.GetExistenceTime() >= 180) { // 180 frames = 3 giây với frame rate 60fps
            // Nếu quả táo tồn tại quá thời gian, tạo một quả táo mới
            MEAT.SetRandomPosition(GRID_COLS_SCREEN, GRID_ROWS_SCREEN);
            MEAT.ResetExistenceTime();
        }



        GamePlay::DrawGrid(GRID_ROWS_SCREEN, GRID_COLS_SCREEN, GRID_SIZE);

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

void GamePlay::setSCR_WIDTH(int SCREEN_WIDTH)
{
    this->SCR_WIDTH = SCREEN_WIDTH;
}

void GamePlay::DrawScore() {
    // Vẽ điểm số bên góc phải của màn hình
    score += 10;
    std::string scoreText = "Score: " + std::to_string(score);
    const char* scoreChar = scoreText.c_str(); // Chuyển đổi thành một con trỏ char

    DrawText(scoreChar, getSCR_WIDTH() - 150, 20, 20, BLACK);
}