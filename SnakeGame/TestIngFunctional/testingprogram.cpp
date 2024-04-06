//#include "raylib.h"
//
//#define SCREEN_WIDTH 800
//#define SCREEN_HEIGHT 450
//
//#define SMALL_GRID_SIZE 10
//#define MEDIUM_GRID_SIZE 20
//#define LARGE_GRID_SIZE 30
//
//typedef enum {
//    SMALL,
//    MEDIUM,
//    LARGE
//} GridSize;
//
//Rectangle smallButton = { 20, 20, 100, 40 };
//Rectangle mediumButton = { 140, 20, 100, 40 };
//Rectangle largeButton = { 260, 20, 100, 40 };
//
//bool buttonsVisible = true; // Biến để theo dõi trạng thái hiển thị của các nút
//GridSize currentGridSize = MEDIUM;
//
//void DrawGrid(int cellSize) {
//    int rows = SCREEN_HEIGHT / cellSize;
//    int cols = SCREEN_WIDTH / cellSize;
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            int x = j * cellSize;
//            int y = i * cellSize;
//            DrawRectangle(x, y, cellSize, cellSize, SKYBLUE);
//            DrawRectangleLines(x, y, cellSize, cellSize, BLACK);
//        }
//    }
//}
//
//void DrawButtons() {
//    if (buttonsVisible) { // Chỉ vẽ nút khi biến buttonsVisible là true
//        DrawRectangleRec(smallButton, LIGHTGRAY);
//        DrawRectangleRec(mediumButton, LIGHTGRAY);
//        DrawRectangleRec(largeButton, LIGHTGRAY);
//
//        DrawText("Small", smallButton.x + 10, smallButton.y + 10, 20, BLACK);
//        DrawText("Medium", mediumButton.x + 10, mediumButton.y + 10, 20, BLACK);
//        DrawText("Large", largeButton.x + 10, largeButton.y + 10, 20, BLACK);
//    }
//}
//
//int main(void) {
//    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Grid Example");
//
//    SetTargetFPS(60);
//
//    while (!WindowShouldClose()) {
//        BeginDrawing();
//        ClearBackground(RAYWHITE);
//
//        if (!buttonsVisible) { // Nếu buttonsVisible là false, chỉ hiển thị lưới
//            if (currentGridSize == SMALL) {
//                DrawGrid(SMALL_GRID_SIZE);
//            }
//            else if (currentGridSize == MEDIUM) {
//                DrawGrid(MEDIUM_GRID_SIZE);
//            }
//            else if (currentGridSize == LARGE) {
//                DrawGrid(LARGE_GRID_SIZE);
//            }
//        }
//
//        DrawButtons();
//
//        if (buttonsVisible) { // Kiểm tra nút nào được nhấn và cập nhật kích thước lưới
//            if (CheckCollisionPointRec(GetMousePosition(), smallButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                currentGridSize = SMALL;
//                buttonsVisible = false; // Ẩn các nút sau khi nút đã được nhấn
//            }
//            else if (CheckCollisionPointRec(GetMousePosition(), mediumButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                currentGridSize = MEDIUM;
//                buttonsVisible = false;
//            }
//            else if (CheckCollisionPointRec(GetMousePosition(), largeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                currentGridSize = LARGE;
//                buttonsVisible = false;
//            }
//        }
//
//        EndDrawing();
//    }
//
//    CloseWindow();
//
//    return 0;
//}
#include "raylib.h"

#define CHOOSE_SCREEN_WIDTH 560
#define CHOOSE_SCREEN_HEIGHT 280
#define GRID_SIZE 30

typedef enum {
    SMALL,
    MEDIUM,
    LARGE
} GridSize;

class GamePlay {
public:
    static void Choose_Mode_GamePlay() {
        InitWindow(CHOOSE_SCREEN_WIDTH, CHOOSE_SCREEN_HEIGHT, "SNAKE GAME");

        SetTargetFPS(60);

        bool openNewWindow = false;

        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            if (!openNewWindow) {
                if (currentGridSize == SMALL) {
                    CloseWindow();
                    GamePlay::Start(720, 560);
                    openNewWindow = true;
                }
                else if (currentGridSize == MEDIUM) {
                    CloseWindow();
                    GamePlay::Start(1280, 720);
                    openNewWindow = true;
                }
                else if (currentGridSize == LARGE) {
                    CloseWindow();
                    GamePlay::Start(1820, 980);
                    openNewWindow = true;
                }
            }

            GamePlay::DrawChooseButtonMode();

            if (buttonsVisible) {
                if (CheckCollisionPointRec(GetMousePosition(), smallButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentGridSize = SMALL;
                    buttonsVisible = false;
                }
                else if (CheckCollisionPointRec(GetMousePosition(), mediumButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentGridSize = MEDIUM;
                    buttonsVisible = false;
                }
                else if (CheckCollisionPointRec(GetMousePosition(), largeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    currentGridSize = LARGE;
                    buttonsVisible = false;
                }
            }

            EndDrawing();
        }
        CloseWindow(); // Tắt cửa sổ SnakeGame khi kết thúc vòng lặp
    }

    static void Start(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Grid Example");

        SetTargetFPS(60);

        int GRID_ROWS = SCREEN_HEIGHT / GRID_SIZE;
        int GRID_COLS = SCREEN_WIDTH / GRID_SIZE;

        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawGrid(GRID_ROWS, GRID_COLS, GRID_SIZE);

            EndDrawing();
        }

        CloseWindow();
    }

    static void DrawChooseButtonMode() {
        if (buttonsVisible) {
            DrawRectangleRec(smallButton, LIGHTGRAY);
            DrawRectangleRec(mediumButton, LIGHTGRAY);
            DrawRectangleRec(largeButton, LIGHTGRAY);

            DrawText("Small", smallButton.x + 10, smallButton.y + 10, 20, BLACK);
            DrawText("Medium", mediumButton.x + 10, mediumButton.y + 10, 20, BLACK);
            DrawText("Large", largeButton.x + 10, largeButton.y + 10, 20, BLACK);
        }
    }

    static void DrawGrid(int rows, int cols, int cellSize)
    {
        for (int i = 0; i < rows; i++) {
            DrawLine(0, i * cellSize, cols * cellSize, i * cellSize, LIGHTGRAY);
        }
        for (int j = 0; j < cols; j++) {
            DrawLine(j * cellSize, 0, j * cellSize, rows * cellSize, LIGHTGRAY);
        }

    }

    static Rectangle smallButton;
    static Rectangle mediumButton;
    static Rectangle largeButton;
    static GridSize currentGridSize;
    static bool buttonsVisible;
};

Rectangle GamePlay::smallButton = { 20, 20, 100, 40 };
Rectangle GamePlay::mediumButton = { 140, 20, 100, 40 };
Rectangle GamePlay::largeButton = { 260, 20, 100, 40 };
GridSize GamePlay::currentGridSize = MEDIUM;
bool GamePlay::buttonsVisible = true;

int main(void) {
    GamePlay::Choose_Mode_GamePlay();

    return 0;
}
