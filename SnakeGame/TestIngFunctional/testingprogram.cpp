#include "raylib.h"
#include <iostream>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Khởi tạo cửa sổ và tạo một màn hình với kích thước cụ thể
    InitWindow(screenWidth, screenHeight, "TESTING INSERT PICTURE");

    // Load ảnh từ đường dẫn cụ thể
    Image image = LoadImage("C:/Users/quoc9/Downloads/1695388601323.png");

    // Thu nhỏ hoặc phóng to ảnh để phù hợp với kích thước của cửa sổ
    ImageResize(&image, screenWidth, screenHeight);

    // Chuyển đổi ảnh thành Texture2D
    Texture2D background = LoadTextureFromImage(image);

    // Giải phóng bộ nhớ của image sau khi đã sử dụng
    UnloadImage(image);

    // Load ảnh icon từ tệp ảnh
    Image icon = LoadImage("snake-icon-png-4.png");

    // Thiết lập icon cho cửa sổ của ứng dụng
    SetWindowIcon(icon);

    // Giải phóng bộ nhớ của icon sau khi đã sử dụng
    UnloadImage(icon);

    SetTargetFPS(60);
    InitAudioDevice();

    Sound fx = LoadSound("C:/Users/quoc9/Downloads/Blue Dream - Cheel.mp3");
    //Sound fx = LoadSound("Recording.wav");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            // Phát âm thanh
            std::cout << "OK" << std::endl;
            PlaySound(fx);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        EndDrawing();
    }

    // Giải phóng bộ nhớ của âm thanh sau khi sử dụng
    CloseAudioDevice();
    // Giải phóng texture và đóng cửa sổ
    UnloadTexture(background);
    CloseWindow();

    return 0;
}
