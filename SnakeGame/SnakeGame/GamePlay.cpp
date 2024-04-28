#include "GamePlay.h"
#include <raylib.h>
#include "Snake.h"
#include"meat.h"
#include<string>

#define CHOOSE_SCREEN_WIDTH 1120
#define CHOOSE_SCREEN_HEIGHT 560
#define GRID_SIZE 30

// Rectangle ten bien = { x , y , Width of rec, Height of rec}
Rectangle easyButton = { 200, 300, 270, 120 };
Rectangle hardcoreButton = { 650, 300, 270, 120 };
Rectangle newGame = { 630, 390, 150, 90 };
Rectangle playAgain = { 340, 390, 150, 90 };
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

    // Load ảnh icon từ tệp ảnh
    Image icon = LoadImage("snake-icon-png-4.png");

    // Thiết lập icon cho cửa sổ của ứng dụng
    SetWindowIcon(icon);

    // Giải phóng bộ nhớ của icon sau khi đã sử dụng
    UnloadImage(icon);

    // Load ảnh từ tệp ảnh
    Image image = LoadImage("Slide1.png");

    // Thu nhỏ hoặc phóng to ảnh để phù hợp với kích thước của cửa sổ
    ImageResize(&image, CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT);

    // Chuyển đổi ảnh thành Texture2D
    Texture2D background = LoadTextureFromImage(image);

    // Giải phóng bộ nhớ của image sau khi đã sử dụng
    UnloadImage(image);

    SetTargetFPS(60);
    int HEIGHT_GAME_SCREEN = 0;
    int WIDTH_GAME_SCREEN = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        //ClearBackground(DARKBROWN);
        DrawTexture(background, 0, 0, WHITE);

        if (CheckCollisionPointRec(GetMousePosition(), easyButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            currentGridSize = SMALL;
            this->buttonsVisible = false; // Ẩn các nút sau khi nút đã được nhấn
            HEIGHT_GAME_SCREEN = 560;
            WIDTH_GAME_SCREEN = 720;
            break;
        }
        else if (CheckCollisionPointRec(GetMousePosition(), hardcoreButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            currentGridSize = MEDIUM;
            this->buttonsVisible = false;
            HEIGHT_GAME_SCREEN = 720;
            WIDTH_GAME_SCREEN = 1280;
            break;
        }
        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(background);
    //this->GameOver(1, WIDTH_GAME_SCREEN, HEIGHT_GAME_SCREEN);
    GamePlay::Start(WIDTH_GAME_SCREEN, HEIGHT_GAME_SCREEN);
    return;
}

void GamePlay::Start(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);


    SetTargetFPS(9);

    int GRID_ROWS_SCREEN = SCREEN_HEIGHT / GRID_SIZE;
    int GRID_COLS_SCREEN = SCREEN_WIDTH / GRID_SIZE;
    int FrameCount = 8;

    SetWindowPosition((GetMonitorWidth(0) - SCREEN_WIDTH) / 2, (GetMonitorHeight(0) - SCREEN_HEIGHT) / 2);

    this->setSCR_WIDTH(SCREEN_WIDTH);

    Snake snake(GRID_COLS_SCREEN / 2, GRID_ROWS_SCREEN / 2, 1, 0);
    snake.Set_SCR_WIDTH(SCREEN_WIDTH);
    meat MEAT(GRID_COLS_SCREEN, GRID_ROWS_SCREEN, snake.body);



    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
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

        snake.Move(GRID_COLS_SCREEN, GRID_ROWS_SCREEN, FrameCount, MEAT); // Di chuyển con rắn
        snake.Draw(); // Vẽ con rắn
        MEAT.Draw();
        snake.DrawScore();

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
            MEAT.SetRandomPosition(GRID_COLS_SCREEN, GRID_ROWS_SCREEN, snake.body);
            MEAT.ResetExistenceTime();
        }


        EndDrawing();
    }

    CloseWindow();
}

void GamePlay::setSCR_WIDTH(int SCREEN_WIDTH)
{
    this->SCR_WIDTH = SCREEN_WIDTH;
}

void GamePlay::GameOver(int Score, int OLD_MODE_WIDTH, int OLD_MODE_HEIGHT)
{
    int MODE = 0;
    SetWindowSize(CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT);
    SetWindowPosition((GetMonitorWidth(0) - CHOOSE_SCREEN_WIDTH) / 2, (GetMonitorHeight(0) - CHOOSE_SCREEN_HEIGHT) / 2);

    // Load ảnh từ tệp ảnh
    Image image = LoadImage("Slide3.png");

    // Thu nhỏ hoặc phóng to ảnh để phù hợp với kích thước của cửa sổ
    ImageResize(&image, CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT);

    // Chuyển đổi ảnh thành Texture2D
    Texture2D background = LoadTextureFromImage(image);

    // Giải phóng bộ nhớ của image sau khi đã sử dụng
    UnloadImage(image);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        //ClearBackground(DARKGRAY);
        DrawTexture(background, 0, 0, WHITE);

        std::string Result = "YOUR SCORE: " + std::to_string(Score);
        const char* Score_Announce = Result.c_str();
        DrawText(Score_Announce, 135 * 2, 100 * 2, 30 * 2, ORANGE);

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
    {
        CloseWindow();
    }
}