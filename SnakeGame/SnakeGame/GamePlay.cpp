#include "GamePlay.h"
#include <raylib.h>
#include "Snake.h"
#include"meat.h"
#include<string>

#define CHOOSE_SCREEN_WIDTH 560
#define CHOOSE_SCREEN_HEIGHT 280
#define GRID_SIZE 30

// Rectangle ten bien = { x , y , Width of rec, Height of rec}
Rectangle smallButton = { 70, 115, 100, 40 };
Rectangle mediumButton = { 225, 115, 100, 40 };
Rectangle largeButton = { 390, 115, 100, 40 };
Rectangle playAgain = { 310, 175, 200, 50 };
Rectangle newGame = { 90,175,170,50 };
GridSize currentGridSize = MEDIUM;

//bool buttonsVisible = true;

int GamePlay::score = 0;

void GamePlay::Choose_Mode_GamePlay()
{
    if (this->FirstGame)
        InitWindow(CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT, "SNAKE GAME");
    else
        SetWindowSize(CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT);

    int screenWidth = GetMonitorWidth(0); // Lấy chiều rộng của màn hình
    int screenHeight = GetMonitorHeight(0); // Lấy chiều cao của màn hình
    int windowX = (screenWidth - CHOOSE_SCREEN_WIDTH) / 2; // Tính toán vị trí X của cửa sổ
    int windowY = (screenHeight - CHOOSE_SCREEN_HEIGHT) / 2; // Tính toán vị trí Y của cửa sổ
    SetWindowPosition(windowX, windowY); // Đặt vị trí của cửa sổ

    SetTargetFPS(60);
    int HEIGHT_GAME_SCREEN = 0;
    int WIDTH_GAME_SCREEN = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBROWN);

        this->DrawChooseButtonMode(); 

        if (this->buttonsVisible) { // Kiểm tra nút nào được nhấn và cập nhật kích thước lưới
            if (CheckCollisionPointRec(GetMousePosition(), smallButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = SMALL;
                this->buttonsVisible = false; // Ẩn các nút sau khi nút đã được nhấn
                HEIGHT_GAME_SCREEN = 560;
                WIDTH_GAME_SCREEN = 720;
                break;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), mediumButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = MEDIUM;
                this->buttonsVisible = false;
                HEIGHT_GAME_SCREEN = 720;
                WIDTH_GAME_SCREEN = 1280;
                break;
            }
            else if (CheckCollisionPointRec(GetMousePosition(), largeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                currentGridSize = LARGE;
                this->buttonsVisible = false;
                HEIGHT_GAME_SCREEN = 880;
                WIDTH_GAME_SCREEN = 1720;
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

    if (this->buttonsVisible) { // Chỉ vẽ nút khi biến buttonsVisible là true
        DrawText("Choose Game Mode ", 50, 20, 50, GREEN);
        DrawRectangleRec(smallButton, LIGHTGRAY);
        DrawRectangleRec(mediumButton, LIGHTGRAY);
        DrawRectangleRec(largeButton, LIGHTGRAY);

        DrawText("Small", smallButton.x + 25, smallButton.y + 10, 20, BLACK);
        DrawText("Medium", mediumButton.x + 15, mediumButton.y + 10, 20, BLACK);
        DrawText("Large", largeButton.x + 20, largeButton.y + 10, 20, BLACK);

        DrawText("Created by UIT_HHQN", 320, 250, 20, SKYBLUE);
    }
}

void GamePlay::Start(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    SetTargetFPS(9);

    int GRID_ROWS_SCREEN = SCREEN_HEIGHT / GRID_SIZE;
    int GRID_COLS_SCREEN = SCREEN_WIDTH / GRID_SIZE;
    int FrameCount = 8;

    SetWindowPosition((GetMonitorWidth(0) - SCREEN_WIDTH)/2, (GetMonitorHeight(0) - SCREEN_HEIGHT)/2);

    this->setSCR_WIDTH(SCREEN_WIDTH);
   
    //Snake::GRID_COLS = GRID_COLS_SCREEN;
    //Snake::GRID_ROWS = GRID_ROWS_SCREEN;
    Snake snake(GRID_COLS_SCREEN / 2, GRID_ROWS_SCREEN / 2, 1, 0);
    snake.Set_SCR_WIDTH(SCREEN_WIDTH);
    meat MEAT(GRID_COLS_SCREEN, GRID_ROWS_SCREEN);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        SetTargetFPS(snake.GetSpeed());
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
        snake.DrawScore();
        MEAT.Draw();

        // Kiểm tra va chạm với thân mình
        if (snake.CheckSelfCollision()) {
            // Nếu có va chạm, kết thúc trò chơi
            this->GameOver(snake.GetScore(), SCREEN_WIDTH, SCREEN_HEIGHT);
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



        //GamePlay::DrawGrid(GRID_ROWS_SCREEN, GRID_COLS_SCREEN, GRID_SIZE);

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

void GamePlay::GameOver(int Score,int OLD_MODE_WIDTH, int OLD_MODE_HEIGHT)
{
    int MODE = 0;
    SetWindowSize(CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT);
    SetWindowPosition((GetMonitorWidth(0) - CHOOSE_SCREEN_WIDTH) / 2, (GetMonitorHeight(0) - CHOOSE_SCREEN_HEIGHT) / 2);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawText("GAME OVER", 130, 30, 50, GREEN);

        std::string Result = "YOUR SCORE: " + std::to_string(Score);
        const char* Score_Announce = Result.c_str();
        DrawText(Score_Announce, 135, 100, 30, ORANGE);
        DrawRectangleRec(playAgain, LIGHTGRAY);
        DrawText("PLAY AGAIN", playAgain.x + 5, playAgain.y + 10, 30, BLACK);

        DrawRectangleRec(newGame, LIGHTGRAY);
        DrawText("NEW GAME", newGame.x + 5, newGame.y + 10, 30, RED);

        if (CheckCollisionPointRec(GetMousePosition(), playAgain) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            MODE = 1;
            break;
        }
        if (CheckCollisionPointRec(GetMousePosition(), newGame) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            MODE = 2;
            break;
        }


        //DrawRectangleRec("PLAY AGAIN !", );
        EndDrawing();
    }
    if (MODE == 1) // Chơi lại
    {
        this->Start(OLD_MODE_WIDTH, OLD_MODE_HEIGHT);
    }
    if (MODE == 2) // Game mới
    {
        this->buttonsVisible = true;
        this->FirstGame = false;
        this->Choose_Mode_GamePlay();
    }
    if (MODE == 0)
        CloseWindow();
}